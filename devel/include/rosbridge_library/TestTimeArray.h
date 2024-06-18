// Generated by gencpp from file rosbridge_library/TestTimeArray.msg
// DO NOT EDIT!


#ifndef ROSBRIDGE_LIBRARY_MESSAGE_TESTTIMEARRAY_H
#define ROSBRIDGE_LIBRARY_MESSAGE_TESTTIMEARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosbridge_library
{
template <class ContainerAllocator>
struct TestTimeArray_
{
  typedef TestTimeArray_<ContainerAllocator> Type;

  TestTimeArray_()
    : times()  {
    }
  TestTimeArray_(const ContainerAllocator& _alloc)
    : times(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<ros::Time, typename ContainerAllocator::template rebind<ros::Time>::other >  _times_type;
  _times_type times;




  typedef boost::shared_ptr< ::rosbridge_library::TestTimeArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosbridge_library::TestTimeArray_<ContainerAllocator> const> ConstPtr;

}; // struct TestTimeArray_

typedef ::rosbridge_library::TestTimeArray_<std::allocator<void> > TestTimeArray;

typedef boost::shared_ptr< ::rosbridge_library::TestTimeArray > TestTimeArrayPtr;
typedef boost::shared_ptr< ::rosbridge_library::TestTimeArray const> TestTimeArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosbridge_library::TestTimeArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosbridge_library

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'rosbridge_library': ['/home/cruiser/catkin_ws/src/rosbridge_library/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosbridge_library::TestTimeArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosbridge_library::TestTimeArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosbridge_library::TestTimeArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "237b97d24fd33588beee4cd8978b149d";
  }

  static const char* value(const ::rosbridge_library::TestTimeArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x237b97d24fd33588ULL;
  static const uint64_t static_value2 = 0xbeee4cd8978b149dULL;
};

template<class ContainerAllocator>
struct DataType< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosbridge_library/TestTimeArray";
  }

  static const char* value(const ::rosbridge_library::TestTimeArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time[] times\n\
";
  }

  static const char* value(const ::rosbridge_library::TestTimeArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.times);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TestTimeArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosbridge_library::TestTimeArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosbridge_library::TestTimeArray_<ContainerAllocator>& v)
  {
    s << indent << "times[]" << std::endl;
    for (size_t i = 0; i < v.times.size(); ++i)
    {
      s << indent << "  times[" << i << "]: ";
      Printer<ros::Time>::stream(s, indent + "  ", v.times[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSBRIDGE_LIBRARY_MESSAGE_TESTTIMEARRAY_H
