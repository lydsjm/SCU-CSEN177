# Name: Lydia Myla
# Date: 9/24/2024
# Title: Lab 1 - Step 3
# Description: add onto sample program to calculate the area of a circle and test it


#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "Mylas" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!"
        exit 1
fi

response="Yes"
echo $response
while [ $response != "No" ]
do
        echo "Enter height of rectangle: "
        read height
        echo "Enter width of rectangle: "
        read width
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"

        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response

done

response_c="Yes"
echo $response_c
while [ $response_c != "No" ]
do
        echo "Enter radius of circle: "
        read radius
        area_c=$(echo "$radius" | awk '{print 3.1415 * $1 * $1}')
        echo "The are of the circle is $area_c"


        echo "Would you like to repeat for another circle [Yes/No]?"
        read response_c

done