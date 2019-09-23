#!/bin/bash

# @file job.sh
# @brief mpi job submission shell script
# @author Jeff Perry <jeffsp@gmail.com>
# @version 1.0
# @date 2013-07-16

# see: http://www.tacc.utexas.edu/user-services/user-guides/stampede-user-guide#running-envs-mpi

# ranger: 3936x16-way 32GB SMP compute nodes (62,976 total cores)
# lonestar: 1888x12-way 12GB SMP compute nodes (22,656 total cores)
# stampede(E5): 6400x16-way 32GB SMP compute nodes (102,400 total cores)
# stampede(MIC Phi): 6400x61-way 8GB SMP compute nodes (i390,400 total cores)

#SBATCH -J hpc_mpi                              # job name
#SBATCH -o out.%j                               # output file name
#SBATCH -e err.%j                               # error file name
#SBATCH -n 64                                   # total tasks, divide by 16 to get number of nodes
#SBATCH -p development                          # queue
#SBATCH -t 00:01:00                             # run time (hh:mm:ss)
#SBATCH --mail-user=jeffsp+stampede@gmail.com   # filter messages with +stampede in the to: field
#SBATCH --mail-type=begin                       # email me when the job starts
#SBATCH --mail-type=end                         # email me when the job finishes
ibrun ./f
