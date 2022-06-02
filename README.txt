    /*  README
     *  TEST-1
     *  line 22 executes exercise 1 then create a rgba img object and write a file that /tmp/test_img_rgba
     *
     *  TEST-2
     *  line 23 executes exercise 2 then read a file as parameter (/tmp/test_img_rgba.ppm) and write a file that /tmp/test_img_read
     *
     *  TEST-3
     *  line 24 executes exercise 3 then read a file inside itself and convert to another channel format
     *  and write a file that /tmp/test_img_rgba_to_grayscale
     *
     *  Some explanation
     *  Channels value in exercise_1 and 3 represents :  1 -> grayscale
     *                                                   3 -> rgb
     *                                                   4 -> rgba
     *
     *  exercise_1 executes between lines from 43 to  67 and then
     *  these lines execute some of those lines between from 50 to 184 in image.cpp
     *
     *  exercise_2 executes between lines from 12 to 17 and then
     *  these lines execute some of those lines between from 128 to 249 in image.cpp
     *
     *  exercise_3 executes between lines from 78 to 106 and then
     *  these lines execute some of those lines between from 128 to 390 in image.cpp
     */