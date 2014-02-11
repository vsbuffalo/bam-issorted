#include <iostream>
#include "api/BamReader.h"

using namespace BamTools;

int main(int argc, const char *argv[]) {
  BamAlignment al;
  int32_t last_refid = -1, last_pos = -1;

  while (al.GetNextAlignmentCore()) {
    if (al.isMappped()) {
      if (al.RefID != last_refid) {
        last_pos = -1;
        if (last_refid > al.RefID) {
          // References IDs are out of order compared to header
          cerr << "Reference ID out of order in filename '" << al.Filename
           <<  "', read name '" << al.Name << "'" << endl;
          exit(1);
        }
        last_refid = al.RefId;
      } else {
        // check to see if position is sorted
        if (last_pos > al.Position) {
          // BAM file is not sorted
          cerr << "Alignment position out of order in filename '" << al.Filename
            << "', read name '" << al.Name << "'" << endl;
          exit(1);
        }
      }
    }
  }
  return 0;
}
