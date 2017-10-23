#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <map>
#include <iomanip>

#include "FilesDbParser.h"

void printBlocks(const std::vector<block_t>& root)
{
   for(size_t i = 0; i < root.size(); i++)
   {
      for(size_t j = 0; j < root[i].header.nFiles; j++)
      {
         std::cout << "-------------------------" << std::endl;
         std::cout << "name: " << std::endl;
         std::cout << std::dec << "index: " << root[i].files[j].index << std::endl;
         std::cout << std::dec << "name: " << std::string((const char*)root[i].files[j].fileName) << std::endl;
         
         std::cout << "info: " << std::endl;
         std::cout << std::dec << "index: " << root[i].infos[j].idx << std::endl;
         std::cout << std::hex << "size: " << root[i].infos[j].size << std::endl;
         std::cout << std::hex << "type: " << root[i].infos[j].type << std::endl;
         
         std::cout << std::hex << "unk1: " << root[i].infos[j].unk1 << std::endl;
         std::cout << std::hex << "unk2: " << root[i].infos[j].unk2 << std::endl;
      }
   }
}

void printHash(const hash_t& hash)
{
   for(size_t k = 0; k < sizeof(hash_t); k++)
   {
      std::cout << std::hex << std::setw(2) << std::setfill('0') << (int32_t)hash.data[k];
   }
   std::cout << std::endl;
}

void printHashes(const std::vector<block_t>& blocks)
{
   for(size_t i = 0; i < blocks.size(); i++)
   {
      std::cout << "---------------------" << std::endl;

      std::cout << std::dec << blocks[i].header.nFiles << std::endl;
      std::cout << std::dec << blocks[i].hash_header.unk1 << std::endl;
      std::cout << std::dec << blocks[i].hash_header.unk2 << std::endl;
      std::cout << std::dec << blocks[i].hash_header.unk3 << std::endl;
      std::cout << std::dec << blocks[i].hash_header.unk4 << std::endl;

      for(size_t j = 0; j < blocks[i].hashes.size(); j++)
      {
         printHash(blocks[i].hashes[j]);
      }
   }
}