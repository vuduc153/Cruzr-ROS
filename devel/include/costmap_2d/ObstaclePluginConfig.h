//#line 2 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the costmap_2d package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __costmap_2d__OBSTACLEPLUGINCONFIG_H__
#define __costmap_2d__OBSTACLEPLUGINCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace costmap_2d
{
  class ObstaclePluginConfigStatics;
  
  class ObstaclePluginConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(ObstaclePluginConfig &config, const ObstaclePluginConfig &max, const ObstaclePluginConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const ObstaclePluginConfig &config1, const ObstaclePluginConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, ObstaclePluginConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const ObstaclePluginConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ObstaclePluginConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const ObstaclePluginConfig &config) const = 0;
      virtual void getValue(const ObstaclePluginConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T ObstaclePluginConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (ObstaclePluginConfig::* field);

      virtual void clamp(ObstaclePluginConfig &config, const ObstaclePluginConfig &max, const ObstaclePluginConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const ObstaclePluginConfig &config1, const ObstaclePluginConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, ObstaclePluginConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const ObstaclePluginConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ObstaclePluginConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const ObstaclePluginConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const ObstaclePluginConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, ObstaclePluginConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, ObstaclePluginConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<ObstaclePluginConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(ObstaclePluginConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("enabled"==(*_i)->name){enabled = boost::any_cast<bool>(val);}
        if("footprint_clearing_enabled"==(*_i)->name){footprint_clearing_enabled = boost::any_cast<bool>(val);}
        if("max_obstacle_height"==(*_i)->name){max_obstacle_height = boost::any_cast<double>(val);}
        if("combination_method"==(*_i)->name){combination_method = boost::any_cast<int>(val);}
      }
    }

    bool enabled;
bool footprint_clearing_enabled;
double max_obstacle_height;
int combination_method;

    bool state;
    std::string name;

    
}groups;



//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool enabled;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool footprint_clearing_enabled;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double max_obstacle_height;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int combination_method;
//#line 218 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("ObstaclePluginConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const ObstaclePluginConfig &__max__ = __getMax__();
      const ObstaclePluginConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const ObstaclePluginConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const ObstaclePluginConfig &__getDefault__();
    static const ObstaclePluginConfig &__getMax__();
    static const ObstaclePluginConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const ObstaclePluginConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void ObstaclePluginConfig::ParamDescription<std::string>::clamp(ObstaclePluginConfig &config, const ObstaclePluginConfig &max, const ObstaclePluginConfig &min) const
  {
    return;
  }

  class ObstaclePluginConfigStatics
  {
    friend class ObstaclePluginConfig;
    
    ObstaclePluginConfigStatics()
    {
ObstaclePluginConfig::GroupDescription<ObstaclePluginConfig::DEFAULT, ObstaclePluginConfig> Default("Default", "", 0, 0, true, &ObstaclePluginConfig::groups);
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.enabled = 0;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.enabled = 1;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.enabled = 1;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<bool>("enabled", "bool", 0, "Whether to apply this plugin or not", "", &ObstaclePluginConfig::enabled)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<bool>("enabled", "bool", 0, "Whether to apply this plugin or not", "", &ObstaclePluginConfig::enabled)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.footprint_clearing_enabled = 0;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.footprint_clearing_enabled = 1;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.footprint_clearing_enabled = 1;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<bool>("footprint_clearing_enabled", "bool", 0, "Whether to clear the robot's footprint of lethal obstacles", "", &ObstaclePluginConfig::footprint_clearing_enabled)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<bool>("footprint_clearing_enabled", "bool", 0, "Whether to clear the robot's footprint of lethal obstacles", "", &ObstaclePluginConfig::footprint_clearing_enabled)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_obstacle_height = 0.0;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_obstacle_height = 50.0;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_obstacle_height = 2.0;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<double>("max_obstacle_height", "double", 0, "The maximum height of any obstacle to be inserted into the costmap in meters.", "", &ObstaclePluginConfig::max_obstacle_height)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<double>("max_obstacle_height", "double", 0, "The maximum height of any obstacle to be inserted into the costmap in meters.", "", &ObstaclePluginConfig::max_obstacle_height)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.combination_method = -2147483648;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.combination_method = 2147483647;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.combination_method = 1;
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<int>("combination_method", "int", 0, "Method for combining two layers", "{'enum_description': 'Method for combining layers enum', 'enum': [{'srcline': 11, 'description': 'Overwrite values', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Overwrite'}, {'srcline': 12, 'description': 'Take the maximum of the values', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Maximum'}, {'srcline': 13, 'description': 'Do nothing', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 99, 'ctype': 'int', 'type': 'int', 'name': 'Nothing'}]}", &ObstaclePluginConfig::combination_method)));
//#line 280 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ObstaclePluginConfig::AbstractParamDescriptionConstPtr(new ObstaclePluginConfig::ParamDescription<int>("combination_method", "int", 0, "Method for combining two layers", "{'enum_description': 'Method for combining layers enum', 'enum': [{'srcline': 11, 'description': 'Overwrite values', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Overwrite'}, {'srcline': 12, 'description': 'Take the maximum of the values', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Maximum'}, {'srcline': 13, 'description': 'Do nothing', 'srcfile': '/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg', 'cconsttype': 'const int', 'value': 99, 'ctype': 'int', 'type': 'int', 'name': 'Nothing'}]}", &ObstaclePluginConfig::combination_method)));
//#line 235 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 235 "/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(ObstaclePluginConfig::AbstractGroupDescriptionConstPtr(new ObstaclePluginConfig::GroupDescription<ObstaclePluginConfig::DEFAULT, ObstaclePluginConfig>(Default)));
//#line 353 "/opt/ros/indigo/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<ObstaclePluginConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<ObstaclePluginConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<ObstaclePluginConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    ObstaclePluginConfig __max__;
    ObstaclePluginConfig __min__;
    ObstaclePluginConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const ObstaclePluginConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static ObstaclePluginConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &ObstaclePluginConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const ObstaclePluginConfig &ObstaclePluginConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const ObstaclePluginConfig &ObstaclePluginConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const ObstaclePluginConfig &ObstaclePluginConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<ObstaclePluginConfig::AbstractParamDescriptionConstPtr> &ObstaclePluginConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<ObstaclePluginConfig::AbstractGroupDescriptionConstPtr> &ObstaclePluginConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const ObstaclePluginConfigStatics *ObstaclePluginConfig::__get_statics__()
  {
    const static ObstaclePluginConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = ObstaclePluginConfigStatics::get_instance();
    
    return statics;
  }

//#line 11 "/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg"
      const int ObstaclePlugin_Overwrite = 0;
//#line 12 "/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg"
      const int ObstaclePlugin_Maximum = 1;
//#line 13 "/home/cruiser/catkin_ws/src/costmap_2d/cfg/ObstaclePlugin.cfg"
      const int ObstaclePlugin_Nothing = 99;
}

#endif // __OBSTACLEPLUGINRECONFIGURATOR_H__
