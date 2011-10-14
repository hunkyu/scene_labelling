//#line 2 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the semantic_label_3d package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __semantic_label_3d__LABELINGCONFIG_H__
#define __semantic_label_3d__LABELINGCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/config_init_mutex.h>

namespace semantic_label_3d
{
  class labelingConfigStatics;
  
  class labelingConfig
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
      
      virtual void clamp(labelingConfig &config, const labelingConfig &max, const labelingConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const labelingConfig &config1, const labelingConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, labelingConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const labelingConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, labelingConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const labelingConfig &config) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T labelingConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (labelingConfig::* field);

      virtual void clamp(labelingConfig &config, const labelingConfig &max, const labelingConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const labelingConfig &config1, const labelingConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, labelingConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const labelingConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, labelingConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const labelingConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }
    };

//#line 20 "cfg/labeling.cfg"
      double minx;
//#line 21 "cfg/labeling.cfg"
      double maxx;
//#line 22 "cfg/labeling.cfg"
      double miny;
//#line 23 "cfg/labeling.cfg"
      double maxy;
//#line 24 "cfg/labeling.cfg"
      double minz;
//#line 25 "cfg/labeling.cfg"
      double maxz;
//#line 26 "cfg/labeling.cfg"
      double minSegSize;
//#line 27 "cfg/labeling.cfg"
      std::string label;
//#line 28 "cfg/labeling.cfg"
      std::string no_skip_label;
//#line 31 "cfg/labeling.cfg"
      bool show_clipped;
//#line 33 "cfg/labeling.cfg"
      bool done;
//#line 34 "cfg/labeling.cfg"
      bool accept_label;
//#line 35 "cfg/labeling.cfg"
      bool new_label;
//#line 36 "cfg/labeling.cfg"
      bool skip_labeled;
//#line 138 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;
      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("labelingConfig::__fromMessage__ called with an unexpected parameter.");
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
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      __toMessage__(msg, __param_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const labelingConfig &__max__ = __getMax__();
      const labelingConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const labelingConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const labelingConfig &__getDefault__();
    static const labelingConfig &__getMax__();
    static const labelingConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    
  private:
    static const labelingConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void labelingConfig::ParamDescription<std::string>::clamp(labelingConfig &config, const labelingConfig &max, const labelingConfig &min) const
  {
    return;
  }

  class labelingConfigStatics
  {
    friend class labelingConfig;
    
    labelingConfigStatics()
    {
//#line 20 "cfg/labeling.cfg"
      __min__.minx = -5.0;
//#line 20 "cfg/labeling.cfg"
      __max__.minx = 10.0;
//#line 20 "cfg/labeling.cfg"
      __default__.minx = -5.0;
//#line 20 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("minx", "double", 0, "minx", "", &labelingConfig::minx)));
//#line 21 "cfg/labeling.cfg"
      __min__.maxx = -5.0;
//#line 21 "cfg/labeling.cfg"
      __max__.maxx = 10.0;
//#line 21 "cfg/labeling.cfg"
      __default__.maxx = 10.0;
//#line 21 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("maxx", "double", 0, "maxx", "", &labelingConfig::maxx)));
//#line 22 "cfg/labeling.cfg"
      __min__.miny = -5.0;
//#line 22 "cfg/labeling.cfg"
      __max__.miny = 10.0;
//#line 22 "cfg/labeling.cfg"
      __default__.miny = -5.0;
//#line 22 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("miny", "double", 0, "miny", "", &labelingConfig::miny)));
//#line 23 "cfg/labeling.cfg"
      __min__.maxy = -5.0;
//#line 23 "cfg/labeling.cfg"
      __max__.maxy = 10.0;
//#line 23 "cfg/labeling.cfg"
      __default__.maxy = 10.0;
//#line 23 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("maxy", "double", 0, "maxy", "", &labelingConfig::maxy)));
//#line 24 "cfg/labeling.cfg"
      __min__.minz = -5.0;
//#line 24 "cfg/labeling.cfg"
      __max__.minz = 5.0;
//#line 24 "cfg/labeling.cfg"
      __default__.minz = -5.0;
//#line 24 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("minz", "double", 0, "minz", "", &labelingConfig::minz)));
//#line 25 "cfg/labeling.cfg"
      __min__.maxz = -5.0;
//#line 25 "cfg/labeling.cfg"
      __max__.maxz = 5.0;
//#line 25 "cfg/labeling.cfg"
      __default__.maxz = 5.0;
//#line 25 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("maxz", "double", 0, "maxz", "", &labelingConfig::maxz)));
//#line 26 "cfg/labeling.cfg"
      __min__.minSegSize = 1.0;
//#line 26 "cfg/labeling.cfg"
      __max__.minSegSize = 50000.0;
//#line 26 "cfg/labeling.cfg"
      __default__.minSegSize = 4.0;
//#line 26 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<double>("minSegSize", "double", 0, "minSegSize", "", &labelingConfig::minSegSize)));
//#line 27 "cfg/labeling.cfg"
      __min__.label = "";
//#line 27 "cfg/labeling.cfg"
      __max__.label = "";
//#line 27 "cfg/labeling.cfg"
      __default__.label = "label";
//#line 27 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<std::string>("label", "str", 0, "label", "", &labelingConfig::label)));
//#line 28 "cfg/labeling.cfg"
      __min__.no_skip_label = "";
//#line 28 "cfg/labeling.cfg"
      __max__.no_skip_label = "";
//#line 28 "cfg/labeling.cfg"
      __default__.no_skip_label = "label";
//#line 28 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<std::string>("no_skip_label", "str", 0, "no_skip_label", "", &labelingConfig::no_skip_label)));
//#line 31 "cfg/labeling.cfg"
      __min__.show_clipped = 0;
//#line 31 "cfg/labeling.cfg"
      __max__.show_clipped = 1;
//#line 31 "cfg/labeling.cfg"
      __default__.show_clipped = 1;
//#line 31 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<bool>("show_clipped", "bool", 0, "show_clipped", "", &labelingConfig::show_clipped)));
//#line 33 "cfg/labeling.cfg"
      __min__.done = 0;
//#line 33 "cfg/labeling.cfg"
      __max__.done = 1;
//#line 33 "cfg/labeling.cfg"
      __default__.done = 0;
//#line 33 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<bool>("done", "bool", 0, "Done?", "", &labelingConfig::done)));
//#line 34 "cfg/labeling.cfg"
      __min__.accept_label = 0;
//#line 34 "cfg/labeling.cfg"
      __max__.accept_label = 1;
//#line 34 "cfg/labeling.cfg"
      __default__.accept_label = 0;
//#line 34 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<bool>("accept_label", "bool", 0, "accept label?", "", &labelingConfig::accept_label)));
//#line 35 "cfg/labeling.cfg"
      __min__.new_label = 0;
//#line 35 "cfg/labeling.cfg"
      __max__.new_label = 1;
//#line 35 "cfg/labeling.cfg"
      __default__.new_label = 0;
//#line 35 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<bool>("new_label", "bool", 0, "add a new label class?", "", &labelingConfig::new_label)));
//#line 36 "cfg/labeling.cfg"
      __min__.skip_labeled = 0;
//#line 36 "cfg/labeling.cfg"
      __max__.skip_labeled = 1;
//#line 36 "cfg/labeling.cfg"
      __default__.skip_labeled = 0;
//#line 36 "cfg/labeling.cfg"
      __param_descriptions__.push_back(labelingConfig::AbstractParamDescriptionConstPtr(new labelingConfig::ParamDescription<bool>("skip_labeled", "bool", 0, "skip already labeled segments", "", &labelingConfig::skip_labeled)));
//#line 239 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<labelingConfig::AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        __description_message__.parameters.push_back(**i);
      __max__.__toMessage__(__description_message__.max, __param_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__); 
    }
    std::vector<labelingConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    labelingConfig __max__;
    labelingConfig __min__;
    labelingConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;
    static const labelingConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static labelingConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &labelingConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const labelingConfig &labelingConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const labelingConfig &labelingConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const labelingConfig &labelingConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<labelingConfig::AbstractParamDescriptionConstPtr> &labelingConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const labelingConfigStatics *labelingConfig::__get_statics__()
  {
    const static labelingConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = labelingConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __LABELINGRECONFIGURATOR_H__
