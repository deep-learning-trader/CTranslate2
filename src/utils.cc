#include "opennmt/utils.h"

#ifdef WITH_MKL
#  include <mkl.h>
#endif

namespace opennmt {

  void init(size_t num_threads) {
#ifdef WITH_MKL
    vmlSetMode(VML_EP);
    if (num_threads > 0) {
      set_num_threads(num_threads);
    }
#endif
  }

  void set_num_threads(size_t num_threads) {
    mkl_set_num_threads(num_threads);
  }

}