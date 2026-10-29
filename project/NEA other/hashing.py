import hashlib
from validation import *


def hashing():
    h = hashlib.new("SHA256")
    b = password_validation().encode('utf 8')
    h.update(b)
    print(h.hexdigest())

hashing()