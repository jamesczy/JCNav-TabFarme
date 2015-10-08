#ifndef _Package_h_
#define _Package_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/PropertyBag.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"
#include "im360/event/PackageEvent.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace archive {

    class I3DAPI Package : virtual public event::EventDispatcher
	{
	public:
        typedef core::SharedPointer<Package>::pointer pointer;

		static const int CREATE_DIRECTORIES = 0x01;
		static const int OVERWRITE_EXISTING = 0x02;

		enum ResultCode
		{
			SUCCESS,
			CANCELED,
			FILE_NOT_FOUND,
			ERROR_IO,
			ERROR_INVALID_PACKAGE,
			ERROR_PASSWORD_MALFORMED,
			ERROR_CREATING_DIRECTORY,
			ERROR_EXISTING_FILE,
			ERROR_MISSING_PACKAGE,
			ERROR_ALREADY_IN_PACKAGE
		};

		struct PackageFile
		{
			bool isFile;
			std::string filePath;
			unsigned long size;
		};

        static Package::pointer create();
		virtual ~Package();
        virtual std::string getClassName() const;

        util::PropertyBag & properties();

		ResultCode open(std::string file, std::string password="");
		ResultCode save(std::string file, std::string password="", int writeFlags=OVERWRITE_EXISTING);
		void clear();

		std::string getPackageFile();

		ResultCode addFile(std::string localFile, std::string packageFile, bool replaceExisting=false);
		ResultCode removeFile(std::string fileName);
		unsigned long getFiles(std::vector<PackageFile> & list);
		unsigned long getFileCount();

		Package::ResultCode extractFile(std::string fileName, std::string destPath, int writeFlags=CREATE_DIRECTORIES|OVERWRITE_EXISTING);
		unsigned long extractAll(std::string destPath, int writeFlags=CREATE_DIRECTORIES|OVERWRITE_EXISTING);

		static std::string getErrorString(ResultCode code);

    protected:
        Package();
        virtual bool init();

	private:
		void *		_package;

	};

}}
#endif
#endif
