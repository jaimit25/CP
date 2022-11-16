#!/bin/bash
function psh(){
	echo "Enter Message :"
	read mssg
	dt=$(date)
	echo "$dt"
	if [ -z "$mssg" ] 
	then  
		echo "message cannot be empty" 
	else 	
		git add .
		git commit -m"${mssg} | $dt "
		git push
		echo "Pushed to CP Repository :)" 
	fi 
}


psh