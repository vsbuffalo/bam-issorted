#include <iostream>
#include <string>
#include "api/BamReader.h"

using namespace BamTools;
using namespace std;

int main(int argc, const char *argv[]) {
  int32_t last_refid = -1, last_pos = -1;
  BamReader reader;
  BamAlignment al;

  if (argc < 2) {
    cerr << "usage: issorted in.bam" << endl;
    exit(1);
  }
  string filename(argv[1]);

  if (!reader.Open(filename)) {
    cerr << "error: cannot open file '" << filename << "'" << endl;
    exit(1);
  }

  while (reader.GetNextAlignment(al)) {
    if (al.IsMapped()) {
      if (al.RefID != last_refid) {
        last_pos = -1;
        if (last_refid > al.RefID) {
          // References IDs are out of order compared to header
          cerr << "Reference ID out of order in filename '" << reader.GetFilename()
           <<  "', read name '" << al.Name << "'" << endl;
          exit(1);
        }
        last_refid = al.RefID;
      } else {
        // check to see if position is sorted
        if (last_pos > al.Position) {
          // BAM file is not sorted
          cerr << "Alignment position out of order in filename '" << reader.GetFilename()
            << "', read name '" << al.Name << "'" << endl;
          exit(1);
        }
        last_pos = al.Position;
      }
    }
  }
  cerr << "'" << reader.GetFilename() << "' is sorted." << endl;
  return 0;
}
