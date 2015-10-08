/*
 *  PropertyBag.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 12/7/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _PropertyBag_h_
#define _PropertyBag_h_

#include "im360/core/I3dObject.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
#include <map>
#include <vector>
namespace im360 {
namespace util {

    // TODO: replace this with a VariantMap

    class I3DAPI PropertyBag : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<PropertyBag>::pointer pointer;
        
        enum PropertyType
		{
			STRING,
			NUMERIC,
            BOOLEAN
		};

		enum RawReadFlags
		{
			RRF_NONE = 0x0000,
            RRF_NUMERIC_AS_FLOATS = 0x0001
		};

        static PropertyBag::pointer create();
        static PropertyBag::pointer create(std::string url);
        
        PropertyBag();
        PropertyBag(std::string url);
        
		virtual ~PropertyBag();
		virtual std::string getClassName() const;
        
		bool hasProperty(std::string name);		
        void parseProperty(const std::string & property);
        
		std::string getString(std::string name, std::string otherwise="");
		float getFloat(std::string name, float otherwise=0);
		double getDouble(std::string name, double otherwise=0);
		int getInt(std::string name, int otherwise=0);
		long getLong(std::string name, long otherwise=0);
		bool getBool(std::string name, bool otherwise=false);
		
		void setFloat(std::string name, float value, int flags=0, bool setFlags=false);
		void setDouble(std::string name, double value, int flags=0, bool setFlags=false);
		void setInt(std::string name, int value, int flags=0, bool setFlags=false);
		void setLong(std::string name, long value, int flags=0, bool setFlags=false);
		void setString(std::string name, std::string value, int flags=0, bool setFlags=false);
		void setBool(std::string name, bool value, int flags=0, bool setFlags=false);
	
		void setUserFlags(std::string name, int flags);
		int getUserFlags(std::string name);

		void removeProperty(std::string name);
		void merge(PropertyBag & bag, bool replaceExisting=false);
		void clear();
		
		bool fromFile(std::string url);
		bool toFile(std::string url);

		unsigned long writeRaw(void * ptr); // pass in NULL to just get the length
		void readRaw(void * ptr, unsigned long length, int flags=0);

		unsigned int getKeys(std::vector<std::string> & keys);

	protected:
        virtual bool init();
		virtual bool init(std::string url);

		struct Property
		{
			std::string		name;
			PropertyType	t;
			std::string		s;
			double			n;
			bool			b;
			bool			h;
			int				flags;
		};

		virtual void propertyAdded(Property & property){ property=property; }
		virtual void propertyValueSet(Property & property){ property=property; }

        Property * getProperty(const std::string & name);

	private:
		typedef std::map<std::string, Property *>	PropertyList;
		typedef PropertyList::iterator				PropertyListIterator;

		PropertyList	_properties;
		
		Property * getAddProperty(std::string name, bool * isNew=NULL, int flags=0, bool setFlags=false);
	};

}}
#endif
#endif
