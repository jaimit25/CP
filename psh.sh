#!/bin/bash
function psh(){
	echo "Enter Message :"
	read mssg
	if [ -z "$mssg" ] 
	then  
		echo "message cannot be empty" 
	else 	
		git add .
		git commit -m"$mssg"
		git push
		echo "Pushed to CP Repository :)" 
	fi 
}


