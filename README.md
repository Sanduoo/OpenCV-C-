# OpenCV-C++

2020-02-04
mask掩膜操作和矩阵有关，基本的操作都基于矩阵：
例如：
灰度图像：
→col
L00	L01	L02↓row
L10	L11	L12
L20	L21	L22
  
RGB图像：(通道为BGR排列)
→col
B00	G00	R00	B01	G01	R01↓row
B10	G10	R10	B11	G11	R11

2020-03-08
今天遇到了“abort() has been called”这个问题
在OpenCV VS2019下基本可以判定是路径或者数据类型不匹配所导致的
