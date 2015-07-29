/*
This file is part of Calculator+
Copyright (C) 2015 Felix Lee

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INFIXTOPOSTFIXCONVERTER_H
#define INFIXTOPOSTFIXCONVERTER_H

#include "InputConverter.h"

class InfixToPostfixConverter : public InputConverter
{
public:
    /** Default constructor */
    InfixToPostfixConverter();
    /** Default destructor */
    virtual ~InfixToPostfixConverter();

    std::string convertToPostfix(const std::string&);

private:
    void convert();
};

#endif // INFIXTOPOSTFIXCONVERTER_H
