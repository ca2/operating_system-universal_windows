// Adapted for composition from uwp by camilo on 2021-09-01 22:17 <3ThomasBS__!#pragma once
#pragma once


#include "acme/filesystem/file/status.h"


namespace windows_runtime
{

   class internal_native_data;

   /////////////////////////////////////////////////////////////////////////////
   // native_buffer - raw unbuffered disk native_buffer I/O

   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS native_buffer
   {
   public:

      internal_native_data * m_pnativedata;


      native_buffer();
      virtual ~native_buffer();


      virtual filesize get_position() const ;
      virtual bool get_status(::file::file_status & rStatus) const ;
      //virtual string GetFileName() const;
      //virtual string GetFileTitle() const;
      virtual ::file::path get_file_path() const ;
      virtual void set_file_path(const ::file::path & pathNewName) ;

      virtual ::extended::status open(const ::file::path & lpszfileName, const ::file::e_open & eopen) ;

      //virtual bool GetStatus(const ::file::path & lpszfileName,::file::file_status& rStatus);

      ///u64 ReadHuge(void * lpBuffer,u64 dwCount);
      //void WriteHuge(const void * lpBuffer,u64 dwCount);

      //virtual __pointer(::file::file) Duplicate() const;

      virtual filesize seek(filesize lOff, ::enum_seek eseek) ;
      virtual void set_size(filesize dwNewLen) ;
      virtual filesize get_size() const ;

      virtual memsize read(void * lpBuf, memsize nCount) ;
      virtual void write(const void * lpBuf, memsize nCount) ;

      virtual void lock(filesize dwPos, filesize dwCount) ;
      virtual void unlock(filesize dwPos, filesize dwCount) ;

      //virtual void Abort();
      virtual void flush() ;
      virtual void close() ;

      virtual bool is_opened() const ;
      //enum BufferCommand { bufferRead,bufferWrite,bufferCommit,bufferCheck };
      //virtual u64 GetBufferPtr(::u32 nCommand,u64 nCount = 0,
      //                              void ** ppBufStart = nullptr,void ** ppBufMax = nullptr);

   };


} // namespace universal_windows





