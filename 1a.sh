#!/bin/sh
#assignment 1

create_stud()
{

  echo "Enter file name"
  read fn
  touch $fn

}

modify_stud()
{
   echo "enter roll_number to be modified "
   read rno
   grep -v "$rno" $fn >> temp
   my temp $fn 
   echo "Roll number :"
   read rno
   
   echo "Name:"
   read name
   
   echo "Total marks:"
   read mark
   echo "$rno $name $mark">>$fn
   
}

read_stud()
{
  cat $fn 
}

insert_stud()
{
  echo "enter roll_number:"
   read rno
  
   echo "enter the name :"
   read name
   
   echo "total marks:"
   read marks
   
   
   echo "$rno $name $mark">>$fn
   
  

}


delete_stud()
{
  echo "Enter the rollno to be deleted:"
  read rno
  grep-v "$rno"$fn >> temp
  mv temp $fn


}

while true
do 
   echo "1.Create"
   echo "2.Display"
   echo "3.Insert"
   echo "4.Modify"
   echo "5.Delete"
   
   read ch
   
   case $ch in
     1)
     create_stud ;;
     2)
     read_stud ;; 
     3)
     insert_stud ;;
     4)
     modify_stud ;;
     5)
     delete_stud ;;
   esac
done

exit
