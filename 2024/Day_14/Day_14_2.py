from collections import defaultdict
import sys
import numpy as np
import cv2

def read_data():
  data = []
  with open("input.in") as f:
    for i in f:
      i = i.split(",",)
      data.append([int(i[0][2:]), int(i[1]), int(i[2][2:]), int(i[3])])
  return data

def solve_p2():
  data = read_data()
  wide = 101
  tall = 103
  N = 6645
  for i in range(N):
    img = np.zeros((tall,wide,1),np.uint8) 
    for j in range(len(data)):
      pos_y = (data[j][1]+i*data[j][3]+i*tall)%tall
      pos_x = (data[j][0]+i*data[j][2]+i*wide)%wide
      img[pos_y][pos_x] = 255
    cv2.imwrite('2024/Day_14/Fotos/imagen'+str(i)+'.jpg', img)

  return 0

if __name__ == "__main__":
  print(solve_p2())