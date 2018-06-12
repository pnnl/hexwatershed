//
// Created by Chang Liao on 4/6/18.
//

#include <iostream>
#include <string>

#include "domain.h"
using namespace std;
int main (int argc, char *argv[])
{
    int error_code=1;

    //initial program running status as success,
    //the status variable changes to 0 if any step fails to proceed.
    std::cout<<"Start to run ecosystem model!"<<std::endl;
    int program_status = 1;
    std::string sConfiguration_file = "";
    sConfiguration_file = "/Users/changliao/workspace/cplus/hexagonhydro/hexagonhydro/src/tinpan.meta";
    if(argc == 0) //at least 2 arguments are needed
        {
        std::cout<<"The following arguments are provided:"<<std::endl;
        std::cout<<argv[1]<<std::endl; //print out all the arguments
        //sConfiguration_file = argv[1];

        }
    else
        {
        std::cout<<"No arguments are provided!"<<std::endl;
        std::cout<<"Please input the configuration file:"<<std::endl;
        //std::cin>>sConfiguration_file;

        }
    //initialize the ecosystem model
    hexagon::domain cDomain(sConfiguration_file);

    //since the class initialization does not have a return value, we check it here directly
    if (cDomain.iFlag_configuration_file == 0) //the configuration file is effective.
        {
        std::cout << "The configuration file does not exit!"  << "\n";
        exit(0);
        }
    //initialize the class member
    cDomain.domain_setup();
    cDomain.domain_read_configuration_file();
    cDomain.domain_retrieve_user_input();
    cDomain.domain_read_data();
    cDomain.domain_delineate_watershed();

    return program_status;

}

