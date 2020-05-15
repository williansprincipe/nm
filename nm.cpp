// nm.cpp
// neuron mpi cpp
// wpf 20200515083700
//

#include<iostream>
#include<string>
#include<mpi.h>

int main(int argc, char* argv[])
{   int run_status=0;

    MPI_Init(&argc,&argv);
    int rank;
    int worldCommSize;
    int nSlaves;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&worldCommSize);
    nSlaves=worldCommSize-1;

    std::string run_status_str=std::to_string(run_status);
    std::string end_msg;
    if (rank==0)
    {
        std::cout<<"nm -- version 20200515075500.\n";
        std::cout<<"worldCommSize="<<worldCommSize
                 <<"; nSlaves="<<nSlaves<<".\n";
        std::cout<<"[master:] Hi!\n";
        end_msg="Program \"nm\"";
        //std::string wbuf;
        //std::cin>>wbuf;
    }
    else
    {
        std::cout<<"[slave "<<rank<<":] Hi!\n";
        end_msg="Process "+std::to_string(rank);
    }
    MPI_Finalize();
    end_msg+=" ended "+((run_status==0)?
                        "successfully":
                        "with error code "+run_status_str)
                      +".\n";
    std::cout<<end_msg;
    return run_status;
}

//
// eof nm.cpp
