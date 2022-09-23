// Adapted for composition by camilo on 2021-09-01 22:17 <3ThomasBS__!
#pragma once


//#include "_windows_runtime.h"
#undef new
#include <winrt/Windows.Storage.h>


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS native_buffer :
      virtual public ::file::file
   {
   public:

            
      bool                                                                 m_bCloseOnDelete;
      ::file::path                                                         m_strFileName;
      ::winrt::Windows::Storage::StorageFile                               m_file = nullptr;
      ::winrt::Windows::Storage::StorageFolder                             m_folder = nullptr;
      ::winrt::Windows::Storage::Streams::IRandomAccessStream              m_stream = nullptr;
      ::file::e_open                                                       m_eopen;

      memory                                                               m_memoryBuffer;


      native_buffer(::winrt::Windows::Storage::StorageFile file, const ::file::e_open & efileopen);
      ~native_buffer() override;

      void assert_ok() const override;
      void dump(dump_context & dumpcontext) const override;

      filesize get_position() const override;
      bool get_status(::file::file_status & rStatus) const override;
      //virtual string GetFileName() const;
      //virtual string GetFileTitle() const;
      ::file::path get_file_path() const override;
      //void set_file_path(const ::file::path & pathNewName) override;
      void open(::winrt::Windows::Storage::StorageFolder folder, const ::file::path & pathFileArgument, const ::file::e_open & efileopenParam);
      void open(const ::file::path & lpszfileName, const ::file::e_open & eopen) override;
      void open(::winrt::Windows::Storage::StorageFile file, const ::file::e_open & eopen);

      //virtual bool GetStatus(const ::file::path & lpszfileName,::file::file_status& rStatus);

      ///u64 ReadHuge(void * lpBuffer,u64 dwCount);
      //void WriteHuge(const void * lpBuffer,u64 dwCount);

      //virtual __pointer(::file::file) Duplicate() const;

      //void put_byte_back(::byte byte) override;

      filesize translate(filesize lOff, ::enum_seek eseek) override;
      void set_size(filesize dwNewLen) override;
      filesize get_size() const override;

      memsize read(void * lpBuf, memsize nCount) override;
      void write(const void * lpBuf, memsize nCount) override;

      void lock(filesize dwPos, filesize dwCount) override;
      void unlock(filesize dwPos, filesize dwCount) override;

      //virtual void Abort();
      void flush() override;
      void close() override;

      bool is_opened() const override;
      //enum BufferCommand { bufferRead,bufferWrite,bufferCommit,bufferCheck };
      //virtual u64 GetBufferPtr(::u32 nCommand,u64 nCount = 0,
      //                              void ** ppBufStart = nullptr,void ** ppBufMax = nullptr);

   };


} // namespace acme_universal_windows




