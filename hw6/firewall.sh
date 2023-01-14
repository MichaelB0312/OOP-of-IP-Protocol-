
#!/bin/bash


packets=$(cat -)

#echo "$packets"
non_hash=$(sed '/^[[:blank:]]*#/d;s/#.*//' "$1")

non_space=$(echo "$non_hash" | sed '/^$/d')

#sed '/^$/d' $non_hash > hashtag_clean.txt

#$echo "$non_space"


while read line; do
  #echo "$line"
  law1=$(echo $line | awk -F, '{print $1}')
  #echo "$law1" # > law1.txt

  law2=$(echo $line | awk -F, '{print $2}')
 # echo "$law2" # > law2.txt

  law3=$(echo $line | awk -F, '{print $3}')
  #echo "$law1" # > law1.txt

  law4=$(echo $line | awk -F, '{print $4}')
  #echo "$law1" # > law1.txt


  #law2=$(echo $row | cut -d "," -f2)
  #echo "$law2" > law2.txt

  #law3=$(echo $row | cut -d "," -f3)
  #echo "$law3" > law3.txt
  #law4=$(echo $row | cut -d "," -f4)

  #echo "$law4" > law4.txt

  #deliver packets to be filterd by firewall.exe
  filtered_pkts=$(echo "$packets" | ./firewall.exe "$law1" 2>/dev/null \
	  | ./firewall.exe "$law2" 2>/dev/null \
	  | ./firewall.exe "$law3" 2>/dev/null \
	  | ./firewall.exe "$law4" 2>/dev/null)
  
  echo "$filtered_pkts"
  valid_pkts+=$(echo $filtered_pkts)
	 # | sort  
  #e02_filtered=$(echo "$packets" | ./firewall.exe "$law2")
  #aw3_filtered=$(echo "$packets" | ./firewall.exe "$law3")
  #aw4_filtered=$(echo "$packets" | ./firewall.exe "$law4")
  #echo "$var1"
  #echo "$var2"
  #echo "$var3"
  #echo "$var4"
 
done <<< "$non_space"

echo "$valid_pkts"
