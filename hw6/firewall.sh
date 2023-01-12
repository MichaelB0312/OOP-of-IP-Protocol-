#!/bin/bash


packets=$(cat -)

#echo "$packets"
non_hash=$(sed '/^[[:blank:]]*#/d;s/#.*//' "$1")

non_space=$(echo "$non_hash" | sed '/^$/d')

#sed '/^$/d' $non_hash > hashtag_clean.txt

#echo "$non_space"


for row in $non_space; do
  law1=$(echo $row | awk -F, '{print $1}' | sed '/^$/d')
  law2=$(echo $row | awk -F, '{print $2}' | sed '/^$/d')
  law3=$(echo $row | awk -F, '{print $3}' | sed '/^$/d')
  law4=$(echo $row | awk -F, '{print $4}' | sed '/^$/d')

  #deliver packets to be filterd by firewall.exe
  echo "$packets" | ./firewall.exe "$law1"\
	  | ./firewall.exe "$law2"\
	  | ./firewall.exe "$law3"\
	  | ./firewall.exe "$law4"\
	  | sort  
  #e02_filtered=$(echo "$packets" | ./firewall.exe "$law2")
  #aw3_filtered=$(echo "$packets" | ./firewall.exe "$law3")
  #aw4_filtered=$(echo "$packets" | ./firewall.exe "$law4")
  #echo "$var1"
  #echo "$var2"
  #echo "$var3"
  #echo "$var4"
 
done     # > splitted_rules.txt


