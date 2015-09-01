#include "elf_file_reader.h"

#include <stdio.h>

#include <memory>
#include <string>

#include "logging.h"

std::unique_ptr<ElfFileReader> ElfFileReader::CreateInstance(const std::string& filename) {
  FILE* fp = fopen(filename.c_str(), "rb");
  if (fp == nullptr) {
    LOG(ERROR) << "failed to open file: " << filename;
    return nullptr;
  }
  LOG(INFO) << "Create ElfFileReader for " << filename;
  std::unique_ptr<ElfFileReader> reader(new ElfFileReader(filename, fp));
  if (!reader->ReadHeader()) {
    return nullptr;
  }
  return reader;
}

ElfFileReader::~ElfFileReader() {
  if (fp_ != nullptr) {
    fclose(fp_);
  }
}

bool ElfFileReader::ReadHeader() {
  size_t nread = fread(&header_, sizeof(header_), 1, fp_);
  if (nread != 1) {
    PLOG(ERROR) << "failed to read header of " << filename_ << ", nread = " << nread;
    return false;
  }
  return true;
}


