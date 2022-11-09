#!/bin/sh
create()
{
	echo "Enter file name"
	read filename
	if [ -f $filename ]
	then
		echo "file exists"
	else
	touch $filename
	fi
	echo "Address Book is created"
	
}
insert()
{
	echo "Enter no of records you want to insert"
	read n
	echo "Insert data like"
	echo "ROLL    NAME	MOBILE NO.	E-mail id		CITY"
	while [ $n -ne 0 ]
	 do
		read a
		echo $a >> $filename
	n=`expr $n - 1`
	done
	echo "data is inserted"
}
display()
{
	echo "STUDENT address book is as follows"
	echo "ROLL    NAME	MOBILE NO.	E-mail id		CITY"
	cat $filename
}
search()
{
	echo " Enter roll number for search"
	read s
	echo "ROLL    NAME	MOBILE NO.	E-mail id		CITY"
	grep -i "$s" $filename

	echo "record is found"
}


delete()
{	
	echo  "Enter the roll number to be deleted"
	read  s
 	grep -v "$s" $filename > filename2 ; mv filename2 $filename
	echo "record is deleted"
}


modify()
{

	echo "Enter roll number to be modify"
	read  s
 	echo  "Enter new record"
	echo "ROLL    NAME	MOBILE NO.	E-mail id		CITY"
	read r
	sed -i "/$s/c $r" $filename
	echo "record is modified"
}



#switch-case

until [ "$ch" = "7" ]; do

echo "*ADDRESS BOOK OF STUDENT*"

echo "1.Create Address book"
echo "2.Insert Record"
echo "3.Display Record"
echo "4.Search Record"
echo "5.Delete Record"
echo "6.Modify Record"
echo "7.exit"
echo "Enter Your Choice "
read ch
case $ch in
	1)create;;
	
	2)insert;;
	
	3)display;;

	4)search;;

	5)delete;;

	6)modify;;

	7) ;;
esac
done
