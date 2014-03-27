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
import threading
from Queue import Queue
from ctypes import *
import math


class ChunkData(object):
    draw_list = None

    def __init__(self, data):
        self.data = data


class ChunkManager(object):
    def __init__(self, seed):
        self.gen_queue = Queue()
        self.cache = {}
        threading.Thread(target=self.run, args=(seed,)).start()

    def get(self, x, y):
        key = (x, y)
        try:
            return self.cache[key]
        except KeyError:
            pass
        self.cache.setdefault(key, None)
        self.gen_queue.put(key, False)
        return None

    def stop(self):
        self.gen_queue.put(None)

    def run(self, seed):
        print 'Initializing tgen...'
        tgen.initialize(seed)
        while True:
            key = self.gen_queue.get()
            if key is None:
                break
            x, y = key
            print 'Generating chunk', x, y
            res = ChunkData(tgen.generate(x, y))
            self.cache[key] = res


class Camera(object):
    up = down = left = right = False
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
            sdl2.keycode.SDLK_d: 'right'
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
        speed = dt * 20.0
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
    glVertex3f(gl_x1, gl_y1, gl_z1) # Top right
    glVertex3f(gl_x2, gl_y1, gl_z1) # Top left
    glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom left
    glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom right
    

    # Top face
    glNormal3f(0.0, 0.0, -1.0)
    glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom left
    glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom right
    glVertex3f(gl_x2, gl_y2, gl_z2) # Top right
    glVertex3f(gl_x1, gl_y2, gl_z2) # Top left
    

    # Bottom face
    glNormal3f(0.0, 0.0, 1.0)
    glVertex3f(gl_x1, gl_y1, gl_z1) # Bottom right
    glVertex3f(gl_x1, gl_y2, gl_z1) # Top right
    glVertex3f(gl_x2, gl_y2, gl_z1) # Top left
    glVertex3f(gl_x2, gl_y1, gl_z1) # Bottom left
    

    # Right face
    glNormal3f(1.0, 0.0, 0.0)
    glVertex3f(gl_x2, gl_y1, gl_z1) # Bottom right
    glVertex3f(gl_x2, gl_y2, gl_z1) # Top right
    glVertex3f(gl_x2, gl_y2, gl_z2) # Top left
    glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom left
    

    # Left Face
    glNormal3f(-1.0, 0.0, 0.0)
    glVertex3f(gl_x1, gl_y1, gl_z1) # Bottom left
    glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom right
    glVertex3f(gl_x1, gl_y2, gl_z2) # Top right
    glVertex3f(gl_x1, gl_y2, gl_z1) # Top left

    glEnd()


class MapViewer(object):
    running = False
    time = 0.0

    def __init__(self):
        sdl2.ext.init()
        flags = sdl2.SDL_WINDOW_OPENGL | sdl2.SDL_WINDOW_RESIZABLE
        self.window = sdl2.ext.Window("cuwo - map viewer", size=(640, 480),
                                      flags=flags)
        self.context = sdl2.video.SDL_GL_CreateContext(self.window.window)
        sdl2.mouse.SDL_SetRelativeMouseMode(True)
        self.chunks = ChunkManager(26879)
        self.camera = Camera()

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

    def draw(self):
        w, h = self.get_size()

        glViewport(0, 0, w, h)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(60.0, w / float(h), 0.1, 10000.0)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

        glEnable(GL_DEPTH_TEST)
        glDisable(GL_TEXTURE_2D)

        glClearColor(0.61, 0.949, 1.0, 1.0)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        self.camera.set()

        glColor4f(0.0, 1.0, 1.0, 1.0)
        glBegin(GL_QUADS)
        w = h = 0.5
        y = -10
        glVertex3f(-w, y, -h)
        glVertex3f(w, y, -h)
        glVertex3f(w, y, h)
        glVertex3f(-w, y, h)
        glEnd()

        chunk = self.chunks.get(32797, 32810)
        if chunk is None:
            return

        if chunk.draw_list is not None:
            glCallList(chunk.draw_list)
            return

        print 'Generating display list'
        chunk.draw_list = glGenLists(1)
        glNewList(chunk.draw_list, GL_COMPILE_AND_EXECUTE)

        voxels = chunk.data.get_dict()
        glBegin(GL_QUADS)

        x_offset = y_offset = z_offset = 0

        for k, v in voxels.iteritems():
            x, y, z = k
            r, g, b = v

            # print 'Pos:', x, y, z
            # print 'Color:', r, g, b

            glColor4ub(r, g, b, 255)

            gl_x1 = x + x_offset
            gl_x2 = gl_x1 + 1.0
            gl_y1 = y + y_offset
            gl_y2 = gl_y1 + 1.0
            gl_z1 = z + z_offset
            gl_z2 = gl_z1 + 1.0

            # Left Face
            # if (!file->is_solid(x, y + 1, z)):
            glNormal3f(0.0, 1.0, 0.0)
            glVertex3f(gl_x1, gl_y2, gl_z1)
            glVertex3f(gl_x1, gl_y2, gl_z2)
            glVertex3f(gl_x2, gl_y2, gl_z2)
            glVertex3f(gl_x2, gl_y2, gl_z1)
            

            # Right face
            # if (!file->is_solid(x, y - 1, z)):
            glNormal3f(0.0, -1.0, 0.0)
            glVertex3f(gl_x1, gl_y1, gl_z1) # Top right
            glVertex3f(gl_x2, gl_y1, gl_z1) # Top left
            glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom left
            glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom right
            

            # Top face
            # if (!file->is_solid(x, y, z + 1)):
            glNormal3f(0.0, 0.0, -1.0)
            glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom left
            glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom right
            glVertex3f(gl_x2, gl_y2, gl_z2) # Top right
            glVertex3f(gl_x1, gl_y2, gl_z2) # Top left
            

            # Bottom face
            # if (!file->is_solid(x, y, z - 1)):
            glNormal3f(0.0, 0.0, 1.0)
            glVertex3f(gl_x1, gl_y1, gl_z1) # Bottom right
            glVertex3f(gl_x1, gl_y2, gl_z1) # Top right
            glVertex3f(gl_x2, gl_y2, gl_z1) # Top left
            glVertex3f(gl_x2, gl_y1, gl_z1) # Bottom left
            

            # Right face
            # if (!file->is_solid(x + 1, y, z)):
            glNormal3f(1.0, 0.0, 0.0)
            glVertex3f(gl_x2, gl_y1, gl_z1) # Bottom right
            glVertex3f(gl_x2, gl_y2, gl_z1) # Top right
            glVertex3f(gl_x2, gl_y2, gl_z2) # Top left
            glVertex3f(gl_x2, gl_y1, gl_z2) # Bottom left
            

            # Left Face
            # if (!file->is_solid(x - 1, y, z)):
            glNormal3f(-1.0, 0.0, 0.0)
            glVertex3f(gl_x1, gl_y1, gl_z1) # Bottom left
            glVertex3f(gl_x1, gl_y1, gl_z2) # Bottom right
            glVertex3f(gl_x1, gl_y2, gl_z2) # Top right
            glVertex3f(gl_x1, gl_y2, gl_z1) # Top left
        
        glEnd()

        glEndList()

        print 'Display list generated'

def main():
    viewer = MapViewer()
    viewer.run()

if __name__ == '__main__':
    main()