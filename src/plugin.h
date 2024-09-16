/*
 * Copyright (C) 2024 Edupals project
 *
 * Author:
 *  Enrique Medina Gremaldos <quique@necos.es>
 *
 * Source:
 *  https://github.com/edupals/qml-module-edupals-base
 *
 * This file is a part of qml-module-edupals-base.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef QML_EDUPALS_BASE_PLUGIN
#define QML_EDUPALS_BASE_PLUGIN

#include <system.hpp>
#include <user.hpp>

#include <QQmlExtensionPlugin>
#include <QObject>
#include <QVariant>
#include <QString>
#include <QList>
#include <QThread>
#include <QVariant>
#include <QJSValue>

class User: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(uint32_t uid MEMBER m_uid)
    Q_PROPERTY(uint32_t gid MEMBER m_gid)

    Q_PROPERTY(QString group MEMBER m_group)
    Q_PROPERTY(QStringList groups MEMBER m_groups)

public:

    User();
    ~User();

protected:

    QString m_name;
    uint32_t m_uid;
    uint32_t m_gid;
    QString m_group;
    QStringList m_groups;

};

class BasePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA (IID "Edupals.Base")

public:
    explicit BasePlugin(QObject *parent = nullptr);
    void registerTypes(const char *uri) override;
};

#endif
