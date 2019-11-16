#This is just a Linux BASH script to run all the simulations

echo "Running ./main.exe with 16 cores for L = 20,40,60,80,100 with 1m MCC, T = 2-2.5, dT = 0.005"
start=$SECONDS
mpirun -np 16 ./main.exe ./data/L20_1m_step0-005.csv out1 20 1000000 2 2.5 0.005
mpirun -np 16 ./main.exe ./data/L40_1m_step0-005.csv out1 40 1000000 2 2.5 0.005
mpirun -np 16 ./main.exe ./data/L60_1m_step0-005.csv out1 60 1000000 2 2.5 0.005
mpirun -np 16 ./main.exe ./data/L80_1m_step0-005.csv out1 80 1000000 2 2.5 0.005
mpirun -np 16 ./main.exe ./data/L100_1m_step0-005.csv out1 100 1000000 2 2.5 0.005
duration=$(( SECONDS - start ))
echo "Time spent on all simulations: $duration s"
