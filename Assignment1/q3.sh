#!/bin/bash
mkdir -p Result
echo "">"Result/output.txt"
calculate_xor(){
	echo  $(("$value1"^"$value2"))
}


compare(){
	if [ "$value1" -eq "$value2" ]; then
		echo "$value1"

	elif [ "$value1" -gt "$value2" ]; then
		echo "$value1"
	else
		echo "$value2"
	fi
}

product(){
	echo $(("$value1"*"$value2"))
}






if [ ! -f "input.txt" ]; then
	echo "input.txt does not exist."
	exit 1
fi



file='input.txt'
while IFS=" " read -r value1 value2 operation; do
	case "$operation" in
		"xor")
			result=$(calculate_xor "value1" "value2")
			echo $xor1
			;;
		"product")
			result=$(product "value1" "value2")
			;;
		"compare")
			result=$(compare "value1" "value2")
			;;
		*)
			echo "Enter a valid operation"
			;;
		esac
		echo "Result of $operation $value1 $value2: $result">>"Result/output.txt"
done < "input.txt"
echo "Done"

