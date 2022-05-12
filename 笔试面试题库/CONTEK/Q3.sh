#!/bin/bash

tmp_file="tmp_file"
output="output"
round1=1
round2=2

generate_output(){
	if [ -e $1 ]
	then
		while read line
		do
			time=`echo $line | cut -d',' -f1`
			seq=`echo $line | cut -d',' -f2`
			# echo $time,$seq
			# echo $line
			origin_line=`grep -E "$time" $output`
			new_line="$origin_line,$seq"
			echo $origin_line
			# echo $seq
			sed -i "s/^$origin_line$/$new_line\\n/g" $output
		done < $1
	fi
}

handle_file(){

	if [ ! -e $tmp_file ]
	then
		touch $tmp_file
	fi

	# echo $2
	if [ "$2" -eq 1 ]
	then
		cat $1 | cut -d',' -f1 >> $tmp_file
	else
		generate_output $1
		echo $1
	fi
	 
}

read_dir(){
	for file in `ls $1` 
	do
		if [ -d $1"/"$file ]
		then
			read_dir $1"/"$file $2 # 递归遍历文件夹
		else
			# echo $1"/"$file # 处理文件
			real_file=$1"/"$file
			# echo $2
			handle_file $real_file $2
		fi
	done
} 

read_dir $1 $round1
cat $tmp_file | sort | uniq > $output
read_dir $1 $round2
