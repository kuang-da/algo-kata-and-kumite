#!/bin/bash
# LeetCodeGo0.1 01152017
# Make sure the input arguments are two
if [ $# -ne 2 ];then
  printf "USAGE: $0 [problem number] ['problem name']\n"
  exit
fi
problemNum=$1
problemName="$2"
fileName=lcGOproblemCounter
# To get the real file dir
function myreadlink() {
  (
  cd $(dirname $1)         # or  cd ${1%/*}
  echo $PWD/$(basename $1) # or  echo $PWD/${1##*/}
  )
}

# Read counter
counter=$(cat $fileName)
counter="$(($counter + 1))"
# Make new dir
problemName=${problemName// /_}
newDir="${counter}_${problemNum}_${problemName}"
printf "$counter" > ${fileName}
mkdir $newDir
# Make new file
cd $newDir
newName="${problemNum}.cpp"
touch ${newName}
# Send the dir into clipboard
newCppDir=$(myreadlink ${newName})
echo $newCppDir | pbcopy

echo "Successfuly created a new practice folder!!!"
echo "New file dir is in your clip board."
echo "This is your ${counter}th problem."
motivate

