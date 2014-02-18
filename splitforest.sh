if [ $# -ne 4 ]
then
  echo "Usage: ./splitforest.sh <input> <outdir> <nev> <nfiles>"
  exit 1
fi

g++ splitforest.C $(root-config --cflags --libs) -Werror -Wall -O2 -o "splitforest.exe"

counter=0
while [ $counter -lt $4 ]; do
  let start=counter*$3
  let end=start+$3
  ./splitforest.exe $1 $start $end
  mv /tmp/splitforest_*.root $2
  let counter=counter+1
done
  
