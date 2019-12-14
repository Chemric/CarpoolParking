#!/bin/bash
counter=0
for ip in $( arp -an -i wlan0 | cut -d ')' -f1 | cut -d '(' -f2)
do
	ping -c 1 -w 1 $ip 2>/dev/null 1>/dev/null
	if [[ "$?" = 0 ]]
	then
		counter=$((counter+1))
		#echo $ip OK
	else
		arp -d $ip
		#echo $ip DISCONNECTED!!!
	fi
	#ping -c 1 -W 1 $ip | grep "0 received"
done
echo $counter clients connected
echo "		"
