import cv2

if __name__ == "__main__":
	img = cv2.imread("D:/Projects/VscodeProjects/Life_Long_Learning/CS50_Start/CS50x2023_MySolution/week4_Memory/ProblemSet4/Problem1/images/01.bmp")
	cv2.imwrite("001.bmp", img)