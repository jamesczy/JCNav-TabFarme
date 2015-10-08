/*
 *  Command.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 07/15/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Command_h_
#define _Command_h_

#include "Variant.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
#include <vector>
namespace im360 {
namespace util {

    class I3DAPI Command
    {
    public:
        Command();
        Command(const std::string & command);
        Command(const std::string & command, std::string & sourceUrl);
        Command(const Command & command);
        virtual ~Command();

        long getNativeHandle() const;

        std::string getCommand() const;
        int getArgCount() const;
        Variant getArg(int index) const;

        std::string getSourceUrl() const;
        
        std::string toString() const;
        bool fromString(const std::string & command);
        bool fromString(const std::string & command, const std::string & sourceUrl);

    private:
        long                    _nativeHandle;
        std::string             _command;
        std::vector<Variant>    _args;
        std::string             _sourceUrl;

    };

}}
#endif
#endif
