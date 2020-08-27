#include "gigasecond.h"

#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond {
boost::posix_time::ptime advance(boost::posix_time::ptime start_time) {
  const boost::posix_time::time_duration gigasecond =
      boost::posix_time::seconds(static_cast<int>(1.0e9));

  return start_time + gigasecond;
}
} // namespace gigasecond
