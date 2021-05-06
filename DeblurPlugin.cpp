#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "DeblurPlugin.h"

void DeblurPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void DeblurPlugin::run() {
   
}

void DeblurPlugin::output(std::string file) { 
   std::string command = "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2020.11; ";
   command += "qiime deblur denoise-16S --i-demultiplexed-seqs "+std::string(PluginManager::prefix())+"/"+parameters["inputfile"]+" --p-trim-length "+parameters["trimlength"]+" --o-representative-sequences "+file+"-rep-seqs.qza --o-table "+file+"-table.qza --p-sample-stats --o-stats "+file+"-deblur-stats.qza; conda deactivate";
 //std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<DeblurPlugin> DeblurPluginProxy = PluginProxy<DeblurPlugin>("Deblur", PluginManager::getInstance());
