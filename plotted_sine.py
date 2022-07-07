import matplotlib.pyplot as plt
import numpy as np

def reduce_angle(angle):
    if angle>=360:
        while angle>=360:
            angle-=360
    if angle>=90 and angle<270:
        return 180-angle
    elif angle>=270 and angle<360:
        return angle-360
    return angle

def fact(x):
    if x<=1:
        return 1
    else:
        return x*fact(x-1)

def calc_sine(angle):
    sine = 0
    for i in range(15):
        exp = 2*i+1
        sine+=pow(-1,i)*pow(angle,exp)/fact(exp)
    return sine

def sin(angles):
    ans = []
    for angle in angles:
        ans.append(calc_sine(reduce_angle(angle)/180*np.pi))
    return ans

x = np.linspace(0,1000,100)
y = sin(x)

plt.plot(x,y)
plt.show()
