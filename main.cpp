#include "elf_file_reader.h"
#include "logging.h"

bool DynamicLoaderMain(const std::string& filename) {
  std::unique_ptr<ElfFileReader> elf_file_reader =
      ElfFileReader::CreateInstance(filename);
  return elf_file_reader != nullptr;
}

static void usage() {
  printf("Usage: dynamic_loader filename\n");
  printf("    dynamic loading shared object specified in filename.\n");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    usage();
    return 1;
  }
  bool ret = DynamicLoaderMain(argv[1]);
  return ret ? 0 : 1;
}
