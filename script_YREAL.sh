#!/bin/sh
for file in *.h
do 
echo $file
sed  's/float/YREAL/g' $file > tmp
mv tmp $file
done
