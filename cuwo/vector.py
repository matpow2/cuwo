from pyrr import Vector3, Quaternion
import numpy as np

def ivec3(x=0, y=0, z=0):
    return Vector3((x, y, z), dtype=np.int32)

def vec3(x=0, y=0, z=0):
    return Vector3((x, y, z), dtype=np.float32)

def qvec3(x=0, y=0, z=0):
    return Vector3((x, y, z), dtype=np.int64)

__all__ = ['Vector3', 'Vector2', 'Quaternion', 'ivec3', 'vec3', 'qvec3']
