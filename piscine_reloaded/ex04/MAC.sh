ifconfig -a | grep "ether*" | cut -d r -f 2 | sed  "s/ //g"
