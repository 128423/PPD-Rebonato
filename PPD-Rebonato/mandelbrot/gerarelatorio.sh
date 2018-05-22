#!/bin/bash
>relatorio.out
while read line  ; do
	if [[ $line =~ "2" ]]; then
		echo ""read $line 
		$media1= read $line
		echo ""read $line 
		$media2= read $line
		echo ""read $line 
		$media3= read $line
		echo ""read $line 
		$media4= read $line
		echo ""read $line 
		$media5= read $line
		echo  "$line treads tempo medio = "  $media/5>> relatorio.out
		echo "entro"
	fi
done < $1