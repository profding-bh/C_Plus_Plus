#!/bin/bash

array_curdir=$(ls)  # get cur dir entry

test -e array_exec && rm array_exec #rm array_exec file,if it exists

for a in ${array_curdir}
do
#file command, get ELF file,and append to array_exec file 
	file ${a} | grep ELF | cut -f1 -d':' >> array_exec
done

cat array_exec # just for assure 
 
array_to_rm=`cat array_exec` #assign 

for a in ${array_to_rm}
do
	rm ${a} #rm file one by one
done

rm array_exec #purge 


