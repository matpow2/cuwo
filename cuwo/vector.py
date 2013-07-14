class Vector3(object):
    def __init__(self, x = 0.0, y = 0.0, z = 0.0):
        self.x = x
        self.y = y
        self.z = z

    def __repr__(self):
        return '<Vector %s %s %s>' % (self.x, self.y, self.z)