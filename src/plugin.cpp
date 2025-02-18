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

#include "plugin.h"

#include <user.hpp>
#include <group.hpp>

#include <QQmlEngine>
#include <QAbstractItemModel>
#include <QMimeData>

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> split(string line,char sep=' ')
{
    vector<string> tokens;

    bool knee=false;
    string tmp;

    for (char c : line) {

        if (c==sep) {
            tokens.push_back(tmp);
            tmp="";
        }
        else {
            tmp=tmp+c;
        }
    }

    tokens.push_back(tmp);

    return tokens;
}

User::User()
{
    try {
        edupals::system::User me = edupals::system::User::me();

        m_name = QString::fromStdString(me.name);
        m_uid = me.uid;
        m_gid = me.gid;

        m_group = QString::fromStdString(me.group().name);

        for (auto group:me.groups()) {
            m_groups<<QString::fromStdString(group.name);
        }
    }
    catch(...) {
        m_name = QString::fromStdString("noname");
        m_uid = 0xffffffff;
        m_gid = 0xffffffff;
        m_group = QString::fromStdString("nogroup");
    }

}

User::~User()
{
}

UserQuery::UserQuery(): m_minUid(1000), m_maxUid(9999)
{
}

QStringList UserQuery::getLocalUsers()
{
    QStringList users;

    try {
        ifstream file;

        file.open("/etc/passwd");
        while (file.good()) {
            string line;
            file.getline(line);
            vector<string> user_line = split(line);
            string user_name = user_line[0];
            string user_uid = user_line[2];

            int uid = std::stoi(user_uid);
            if (uid >= m_minUid and uid <= m_maxUid) {
                users<<QString::fromStdString(user_name);
            }

        }
        file.close();
    }
    catch(...) {
        cerr<<"Failed to read passwd file"<<endl;
    }

    return users;
}

BasePlugin::BasePlugin(QObject* parent) : QQmlExtensionPlugin(parent)
{
}

void BasePlugin::registerTypes(const char* uri)
{
    qmlRegisterType<User> (uri, 1, 0, "User");
    qmlRegisterType<UserQuery> (uri, 1, 0, "UserQuery");
    qmlRegisterAnonymousType<QMimeData>(uri, 1);
    
}
