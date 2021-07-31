Name: Huihong Zheng
You will use this exact Makefile for your Homework #2.
Failure to do so will result in deduction of points.

# To compile on terminal type
  make clean
  make all

# To delete executables and object file type
  make clean

# To run the program :

./test_points2d

^^In that case you will provide input from standard input.

# To run with a given file that is redirected to standard input:

```
./test_points2d < test_input_file.txt
```



# instructions to run my program: 

```
g++  -std=c+=14 -o test_points2d  test_points2d.cc   
```

```
./test_points2d < test_input_file.txt
```

# Goal
```
The goal of project/hw is to help understanding "Big Five" and different overloading operators.
This project/hw can be used to add different 2D coordinate points together without doing them manually.
```
# TestPart1

* Will be testing on the "Big Five"
1. copy constructor
2. copy assignment
3. move constructor
4. move assignment
5. destructor

# TestPart2
* Will be testing on overloarding operators such as "<<" , "+", and "[]" 


