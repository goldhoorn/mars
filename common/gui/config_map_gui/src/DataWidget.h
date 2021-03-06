/*
 *  Copyright 2014, DFKI GmbH Robotics Innovation Center
 *
 *  This file is part of the MARS simulation framework.
 *
 *  MARS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  MARS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with MARS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * \file DataWidget.h
 * \author Malte Langosz
 * \brief 
 **/

#ifndef DATA_WIDGET_H
#define DATA_WIDGET_H

#ifdef _PRINT_HEADER_
#warning "DataWidget.h"
#endif

#include <mars/main_gui/PropertyDialog.h>
#include <mars/main_gui/BaseWidget.h>
#include <mars/utils/ConfigData.h>

#include <vector>
#include <set>

#include <QWidget>
#include <QCloseEvent>
#include <QMutex>

namespace mars {

  using namespace std;

  namespace config_map_gui {

    class DataWidget : public main_gui::BaseWidget,
                       public main_gui::PropertyCallback {
    
                         Q_OBJECT;
      
    public:
      DataWidget(mars::cfg_manager::CFGManagerInterface *cfg, QWidget *parent = 0);
      ~DataWidget();
    
      virtual void valueChanged(QtProperty *property, const QVariant &value);
    
      main_gui::PropertyDialog *pDialog;
      void setConfigMap(const std::string &name, const utils::ConfigMap &map);
      void addConfigMap(const std::string &name, utils::ConfigMap &map);
      void updateConfigMap(const std::string &name, const utils::ConfigMap &map);
      void updateConfigMapI(const std::string &name, const utils::ConfigMap &map);
      const utils::ConfigMap& getConfigMap();
      void clearGUI();

    signals:
      void mapChanged();

    private:
      QMutex addMutex;
      utils::ConfigMap config;
      map<QtVariantProperty*, utils::ConfigItem*> dataMap;
      map<QtVariantProperty*, utils::ConfigMap*> addMap;
      map<std::string, QtVariantProperty*> propMap;
      std::string addKeyStr, cname;
      bool ignore_change;
      QtVariantProperty* addProperty;

    private slots:
      void addKey();

    protected slots:
      void timerEvent(QTimerEvent* event);
      virtual void accept();
      virtual void reject();

    };
  
  } // end of namespace config_map_gui

} // end of namespace mars 

#endif // DATA_WIDGET_H
  
