# -*- coding: utf-8 -*-

import math

def f(x):
    math.sin(x*x)

def Simp(n, a, b):
    s=0
    h=(b-a)/n
    for i in range(1, n, 2):
        s+= f(a + (i-1)*h) + 4* f(a+  i*h) + f(a+ (i+1)*h)
    return h/3*s

def Rect(n, a, b):
    s=0
    h= (b-a)/n
    for i in range(1, n):
        s+= f(a + i*h)
    return h* (f(a)/2 + s + f(b)/2)

a=0
b=1
e=0.0001 
n=20
while abs((Simp(n,a,b)- Simp(n//2, a, b))/Simp(n, a, b)) >=e:
    n*=2
print(n, Simp(n,a,b), abs((Simp(n,a,b)- Simp(n//2, a, b))/Simp(n, a, b)))

n=20
while abs((Rect(n,a,b)- Rect(n//2, a, b))/Rect(n, a, b)) >=e:
    n*=2
print(n, Rect(n,a,b), abs((Rect(n,a,b)- Rect(n//2, a, b))/Rect(n, a, b)))
