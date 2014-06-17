# Copyright (c) Mathias Kaerlev 2013-2014.
#
# This file is part of cuwo.
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

import sys
sys.path.append('.')
from cuwo import tgen
from cuwo import euclid
import sdl2
import sdl2.ext
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.constants import GLfloat_4
from OpenGL.GL import shaders
from OpenGL.GL.ARB.vertex_buffer_object import *
import threading
from queue import PriorityQueue, Full
from ctypes import *
import math
import os


FLOAT_SIZE = 4
VERTEX_SIZE = 6 * FLOAT_SIZE + 4
QUAD_SIZE = VERTEX_SIZE * 4


class ChunkData(object):
    data = None
    vbo = None

    def __init__(self, data):
        self.data = data

    def create_vbo(self):
        data, size = self.data.get_data_pointer()
        self.vertex_count = size * 4
        size *= QUAD_SIZE
        self.vbo = glGenBuffersARB(1)
        p = c_void_p(data)
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, self.vbo)
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, size, p, GL_STATIC_DRAW)
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0)
        self.data = None

    @staticmethod
    def begin():
        glEnableClientState(GL_VERTEX_ARRAY)
        glEnableClientState(GL_NORMAL_ARRAY)
        glEnableClientState(GL_COLOR_ARRAY)

    @staticmethod
    def end():
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0)
        glDisableClientState(GL_VERTEX_ARRAY)
        glDisableClientState(GL_NORMAL_ARRAY)
        glDisableClientState(GL_COLOR_ARRAY)

    def draw(self):
        if self.vbo is None:
            self.create_vbo()
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, self.vbo)
        glVertexPointer(3, GL_FLOAT, VERTEX_SIZE, c_void_p(0))
        glNormalPointer(GL_FLOAT, VERTEX_SIZE, c_void_p(FLOAT_SIZE * 3))
        glColorPointer(4, GL_UNSIGNED_BYTE, VERTEX_SIZE,
                       c_void_p(FLOAT_SIZE * 6))
        glDrawArrays(GL_QUADS, 0, self.vertex_count)


class ChunkManager(object):
    running = True

    def __init__(self, parent):
        self.parent = parent
        self.gen_queue = PriorityQueue(1)
        self.cache = {}
        threading.Thread(target=self.run).start()

    def get(self, x, y):
        key = (x, y)
        try:
            return self.cache[key]
        except KeyError:
            pass
        try:
            self.gen_queue.put(key, False)
        except Full:
            return None
        self.cache.setdefault(key, None)
        return None

    def get_all(self):
        for value in self.cache.values():
            if value is None:
                continue
            yield value

    def stop(self):
        self.running = False

    def run(self):
        print('Initializing tgen...')
        tgen.initialize(self.parent.seed, './data/')
        while self.running:
            key = self.gen_queue.get()
            x, y = key
            # print 'Generating chunk', x, y
            off_x = (x - self.parent.chunk_x) * 256.0
            off_y = (y - self.parent.chunk_y) * 256.0
            data = tgen.generate(x, y).get_render(off_x, off_y)
            res = ChunkData(data)
            self.cache[key] = res


class Camera(object):
    up = down = left = right = False
    shift = False
    x_rot = -27.0
    z_rot = 244

    def __init__(self):
        self.pos = euclid.Vector3(40.31, 158.36, 173.21)

    def on_mouse(self, dx, dy):
        self.z_rot -= dx
        self.x_rot -= dy

    def get_rot(self):
        rot = euclid.Quaternion()
        rot.rotate_axis(math.radians(self.z_rot),
                        euclid.Vector3(0.0, 0.0, 1.0))
        rot.rotate_axis(math.radians(self.x_rot),
                        euclid.Vector3(1.0, 0.0, 0.0))
        return rot

    def on_key(self, key, value):
        keys = {
            sdl2.keycode.SDLK_w: 'up',
            sdl2.keycode.SDLK_s: 'down',
            sdl2.keycode.SDLK_a: 'left',
            sdl2.keycode.SDLK_d: 'right',
            sdl2.keycode.SDLK_LSHIFT: 'shift',
            sdl2.keycode.SDLK_RSHIFT: 'shift'
        }
        if key not in keys:
            return
        setattr(self, keys[key], value)

    def update(self, dt):
        move = euclid.Vector3()
        if self.up:
            move.y = 1.0
        elif self.down:
            move.y = -1.0
        if self.left:
            move.x = -1.0
        elif self.right:
            move.x = 1.0
        if self.shift:
            speed = 150
        else:
            speed = 50
        speed *= dt
        self.pos += self.get_rot() * (move * speed)

    def set(self):
        rot = self.get_rot()
        look_vec = rot * euclid.Vector3(0.0, 1.0, 0.0)
        up_vec = rot * euclid.Vector3(0.0, 0.0, 1.0)
        look_vec += self.pos
        gluLookAt(self.pos.x, self.pos.y, self.pos.z,
                  look_vec.x, look_vec.y, look_vec.z,
                  up_vec.x, up_vec.y, up_vec.z)


def draw_cube(x, y, z, r, g, b):
    glBegin(GL_QUADS)
    glColor4ub(r, g, b, 255)

    gl_x1 = x
    gl_x2 = gl_x1 + 1.0
    gl_y1 = y
    gl_y2 = gl_y1 + 1.0
    gl_z1 = z
    gl_z2 = gl_z1 + 1.0

    # Left Face
    glNormal3f(0.0, 1.0, 0.0)
    glVertex3f(gl_x1, gl_y2, gl_z1)
    glVertex3f(gl_x1, gl_y2, gl_z2)
    glVertex3f(gl_x2, gl_y2, gl_z2)
    glVertex3f(gl_x2, gl_y2, gl_z1)

    # Right face
    glNormal3f(0.0, -1.0, 0.0)
    glVertex3f(gl_x1, gl_y1, gl_z1)  # Top right
    glVertex3f(gl_x2, gl_y1, gl_z1)  # Top left
    glVertex3f(gl_x2, gl_y1, gl_z2)  # Bottom left
    glVertex3f(gl_x1, gl_y1, gl_z2)  # Bottom right

    # Top face
    glNormal3f(0.0, 0.0, -1.0)
    glVertex3f(gl_x1, gl_y1, gl_z2)  # Bottom left
    glVertex3f(gl_x2, gl_y1, gl_z2)  # Bottom right
    glVertex3f(gl_x2, gl_y2, gl_z2)  # Top right
    glVertex3f(gl_x1, gl_y2, gl_z2)  # Top left

    # Bottom face
    glNormal3f(0.0, 0.0, 1.0)
    glVertex3f(gl_x1, gl_y1, gl_z1)  # Bottom right
    glVertex3f(gl_x1, gl_y2, gl_z1)  # Top right
    glVertex3f(gl_x2, gl_y2, gl_z1)  # Top left
    glVertex3f(gl_x2, gl_y1, gl_z1)  # Bottom left

    # Right face
    glNormal3f(1.0, 0.0, 0.0)
    glVertex3f(gl_x2, gl_y1, gl_z1)  # Bottom right
    glVertex3f(gl_x2, gl_y2, gl_z1)  # Top right
    glVertex3f(gl_x2, gl_y2, gl_z2)  # Top left
    glVertex3f(gl_x2, gl_y1, gl_z2)  # Bottom left

    # Left Face
    glNormal3f(-1.0, 0.0, 0.0)
    glVertex3f(gl_x1, gl_y1, gl_z1)  # Bottom left
    glVertex3f(gl_x1, gl_y1, gl_z2)  # Bottom right
    glVertex3f(gl_x1, gl_y2, gl_z2)  # Top right
    glVertex3f(gl_x1, gl_y2, gl_z1)  # Top left

    glEnd()


class GLSLShader(object):
    def __init__(self, name):
        shader_dir = os.path.join(os.path.dirname(__file__), 'shaders')
        vert_path = os.path.join(shader_dir, '%s.vert' % name)
        frag_path = os.path.join(shader_dir, '%s.frag' % name)
        vert_data = open(vert_path, 'rb').read()
        frag_data = open(frag_path, 'rb').read()
        vert_shader = shaders.compileShader(vert_data, GL_VERTEX_SHADER)
        frag_shader = shaders.compileShader(frag_data, GL_FRAGMENT_SHADER)
        self.program = shaders.compileProgram(vert_shader, frag_shader)

    def bind(self):
        shaders.glUseProgram(self.program)

    def uniform1i(self, name, value):
        loc = glGetUniformLocation(self.program, name)
        shaders.glUniform1i(loc, value)

    def uniform1f(self, name, value):
        loc = glGetUniformLocation(self.program, name)
        shaders.glUniform1f(loc, value)

    def uniform2f(self, name, val1, val2):
        loc = glGetUniformLocation(self.program, name)
        shaders.glUniform2f(loc, val1, val2)

    def unbind(self):
        shaders.glUseProgram(0)


class MapViewer(object):
    running = False
    time = 0.0
    use_ssao = True
    old_render_size = None
    znear = 0.1
    zfar = 512.0
    old_chunk = None

    def __init__(self, x, y, seed):
        self.chunk_x = x
        self.chunk_y = y
        self.seed = seed
        sdl2.ext.init()
        flags = sdl2.SDL_WINDOW_OPENGL | sdl2.SDL_WINDOW_RESIZABLE

        sdl2.video.SDL_GL_SetAttribute(sdl2.video.SDL_GL_MULTISAMPLEBUFFERS, 1)
        sdl2.video.SDL_GL_SetAttribute(sdl2.video.SDL_GL_MULTISAMPLESAMPLES, 4)
        self.window = sdl2.ext.Window("cuwo - map viewer", size=(640, 480),
                                      flags=flags)
        self.context = sdl2.video.SDL_GL_CreateContext(self.window.window)
        sdl2.mouse.SDL_SetRelativeMouseMode(True)
        self.chunks = ChunkManager(self)
        self.camera = Camera()
        renderer = glGetString(GL_RENDERER)
        self.use_ssao = b'Intel HD' not in renderer
        self.init_ssao()

    def init_ssao(self):
        if not self.use_ssao:
            return
        self.ssao_shader = GLSLShader('ssao')

        self.depth_texture = glGenTextures(1)
        glBindTexture(GL_TEXTURE_2D, self.depth_texture)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP)
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP)
        glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_INTENSITY)

        self.color_texture = glGenTextures(1)
        glBindTexture(GL_TEXTURE_2D, self.color_texture)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)

        self.ssao_shader.bind()
        self.ssao_shader.uniform1i("color_texture", 0)
        self.ssao_shader.uniform1i("depth_texture", 1)
        self.ssao_shader.uniform1f("znear", self.znear * 0.02)
        self.ssao_shader.uniform1f("zfar", self.zfar * 0.02)
        self.ssao_shader.unbind()

    def update_ssao(self):
        if self.old_render_size == self.render_size:
            return
        w, h = self.render_size
        glBindTexture(GL_TEXTURE_2D, self.color_texture)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA,
                     GL_UNSIGNED_BYTE, None)
        glBindTexture(GL_TEXTURE_2D, self.depth_texture)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
                     w, h, 0, GL_DEPTH_COMPONENT, GL_FLOAT, None)

        self.ssao_shader.bind()
        self.ssao_shader.uniform2f("texture_size", float(w), float(h))
        self.ssao_shader.unbind()
        self.old_render_size = self.render_size

    def apply_ssao(self):
        if not self.use_ssao:
            return
        w, h = self.render_size
        self.update_ssao()

        glPushAttrib(GL_ENABLE_BIT)
        glMatrixMode(GL_PROJECTION)
        glPushMatrix()
        glLoadIdentity()
        gluOrtho2D(0, w, 0, h)
        glMatrixMode(GL_MODELVIEW)
        glPushMatrix()
        glDisable(GL_DEPTH_TEST)
        glLoadIdentity()

        # texture 0, color
        glActiveTexture(GL_TEXTURE0)
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, self.color_texture)
        glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, w, h, 0)

        # texture 1, depth
        glActiveTexture(GL_TEXTURE1)
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, self.depth_texture)
        glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 0, 0, w, h, 0)

        off_x = off_y = 0
        x2 = off_x + w
        y2 = off_y + h

        self.ssao_shader.bind()

        glColor4f(1.0, 1.0, 1.0, 1.0)
        glDisable(GL_BLEND)
        glBegin(GL_QUADS)
        glTexCoord2f(0.0, 0.0)
        glVertex2i(off_x, off_y)
        glTexCoord2f(1.0, 0.0)
        glVertex2i(x2, off_y)
        glTexCoord2f(1.0, 1.0)
        glVertex2i(x2, y2)
        glTexCoord2f(0.0, 1.0)
        glVertex2i(off_x, y2)
        glEnd()
        glEnable(GL_BLEND)

        glBindTexture(GL_TEXTURE_2D, 0)
        glActiveTexture(GL_TEXTURE0)
        glDisable(GL_TEXTURE_2D)
        self.ssao_shader.unbind()

        glPopMatrix()
        glMatrixMode(GL_PROJECTION)
        glPopMatrix()
        glMatrixMode(GL_MODELVIEW)
        glPopAttrib()

    def run(self):
        self.running = True

        self.start_time = sdl2.timer.SDL_GetPerformanceCounter()
        self.freq = float(sdl2.timer.SDL_GetPerformanceFrequency())

        while self.running:
            try:
                self.iterate()
            except:
                import traceback
                traceback.print_exc()
                self.running = False
                break
        self.chunks.stop()
        sdl2.ext.quit()

    def iterate(self):
        event = sdl2.events.SDL_Event()
        while sdl2.events.SDL_PollEvent(ctypes.byref(event), 1):
            if event.type == sdl2.events.SDL_QUIT:
                self.running = False
                return
            elif event.type == sdl2.events.SDL_MOUSEMOTION:
                self.on_mouse_event(event)
            elif event.type in (sdl2.events.SDL_KEYDOWN,
                                sdl2.events.SDL_KEYUP):
                self.on_key_event(event)
        new_time = sdl2.timer.SDL_GetPerformanceCounter()
        dt = (new_time - self.start_time) / self.freq
        self.time += dt
        self.start_time = new_time
        self.update(dt)
        self.draw()
        self.apply_ssao()
        sdl2.video.SDL_GL_SwapWindow(self.window.window)

    def on_mouse_event(self, event):
        dx = event.motion.xrel
        dy = event.motion.yrel
        self.camera.on_mouse(dx, dy)

    def on_key_event(self, event):
        key = event.key.keysym.sym
        self.camera.on_key(key, event.key.state == 1)

    def get_size(self):
        w, h = c_int(), c_int()
        sdl2.video.SDL_GL_GetDrawableSize(self.window.window,
                                          byref(w), byref(h))
        return w.value, h.value

    def update(self, dt):
        self.camera.update(dt)

    def set_lighting(self):
        v1 = euclid.Vector3(0.3, -0.7, -0.6).normalized()
        light1_position = GLfloat_4(v1.x, v1.y, v1.z, 0.0)
        diffuse = 0.6
        light_diffuse = GLfloat_4(diffuse, diffuse, diffuse, 1.0)
        light_ambient = GLfloat_4(0.0, 0.0, 0.0, 1.0)
        specular = 0.0
        light_specular = GLfloat_4(specular, specular, specular, 1.0)
        glLightfv(GL_LIGHT0, GL_POSITION, light1_position)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse)
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient)
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular)
        v2 = euclid.Vector3(-0.3, 0.7, -0.6).normalized()
        light2_position = GLfloat_4(v2.x, v2.y, v2.z, 0.0)
        glLightfv(GL_LIGHT1, GL_POSITION, light2_position)
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse)
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient)
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular)
        f = 0.6
        light_model = GLfloat_4(f, f, f, 1.0)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_model)

    def draw(self):
        w, h = self.render_size = self.get_size()

        glViewport(0, 0, w, h)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(60.0, w / float(h), self.znear, self.zfar)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        glEnable(GL_DEPTH_TEST)
        glDisable(GL_TEXTURE_2D)
        glEnable(GL_CULL_FACE)
        glEnable(GL_BLEND)
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
        glClearDepth(1.0)
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE)
        glEnable(GL_LINE_SMOOTH)

        # lighting
        glShadeModel(GL_FLAT)
        glEnable(GL_NORMALIZE)
        glEnable(GL_LIGHTING)
        glEnable(GL_LIGHT0)
        glEnable(GL_LIGHT1)
        glEnable(GL_COLOR_MATERIAL)
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)

        glClearColor(0.61, 0.949, 1.0, 1.0)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        self.camera.set()
        self.set_lighting()

        # glDisable(GL_TEXTURE_2D)

        # glColor4f(1.0, 0.0, 0.0, 1.0)
        # glBegin(GL_QUADS)
        # w = h = 100
        # y = -10
        # glVertex3f(-w, y, -h)
        # glVertex3f(w, y, -h)
        # glVertex3f(w, y, h)
        # glVertex3f(-w, y, h)
        # glEnd()

        pos = self.camera.pos
        x = self.chunk_x + int(pos.x / 256.0)
        y = self.chunk_y + int(pos.y / 256.0)

        chunk = (x, y)
        if chunk != self.old_chunk:
            print('Current chunk:', x, y)
            self.old_chunk = chunk

        ChunkData.begin()

        self.chunks.get(x, y)
        self.chunks.get(x-1, y)
        self.chunks.get(x+1, y)
        self.chunks.get(x, y+1)
        self.chunks.get(x, y-1)
        self.chunks.get(x-1, y+1)
        self.chunks.get(x+1, y+1)
        self.chunks.get(x-1, y-1)
        self.chunks.get(x+1, y-1)

        for chunk in self.chunks.get_all():
            chunk.draw()

        ChunkData.end()


def main():
    viewer = MapViewer(32803, 32803, 26879)
    viewer.run()

if __name__ == '__main__':
    main()