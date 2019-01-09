#pragma once

#include <cstdint>

#include <memory>
#include <map>
#include <iostream>

#include <boost/filesystem.hpp>

#include "IF00DKeyEncryptor.h"
#include "ICryptoOperations.h"

#include "Utils.h"

class FilesDbParser;
class UnicvDbParser;

class PfsPageMapper
{
private:
   std::map<std::uint32_t, sce_junction> m_pageMap;
   std::set<sce_junction> m_emptyFiles;

private:
   std::shared_ptr<ICryptoOperations> m_cryptops;
   std::shared_ptr<IF00DKeyEncryptor> m_iF00D;
   std::ostream& m_output;
   unsigned char m_klicensee[0x10];
   boost::filesystem::path m_titleIdPath;

public:
   PfsPageMapper(std::shared_ptr<ICryptoOperations> cryptops, std::shared_ptr<IF00DKeyEncryptor> iF00D, std::ostream& output, const unsigned char* klicensee, boost::filesystem::path titleIdPath);

public:
   int bruteforce_map(const std::unique_ptr<FilesDbParser>& filesDbParser, const std::unique_ptr<UnicvDbParser>& unicvDbParser);

   int load_page_map(boost::filesystem::path filepath, std::map<std::uint32_t, std::string>& pageMap);
};