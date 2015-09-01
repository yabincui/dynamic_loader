#ifndef ELF_FILE_READER_H_
#define ELF_FILE_READER_H_

#include <link.h>
#include <stdio.h>

#include <memory>
#include <string>

class ElfFileReader {
 public:
	static std::unique_ptr<ElfFileReader> CreateInstance(const std::string& filename);

	~ElfFileReader();

 private:
	ElfFileReader(const std::string& filename, FILE* fp)
      : filename_(filename), fp_(fp) {
	}

	bool ReadHeader();

	const std::string filename_;
	FILE* fp_;
	ElfW(Ehdr) header_;
};

#endif  // ELF_FILE_READER_H_
