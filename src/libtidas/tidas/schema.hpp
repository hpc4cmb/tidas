/*
  TImestream DAta Storage (TIDAS)
  (c) 2014-2015, The Regents of the University of California, 
  through Lawrence Berkeley National Laboratory.  See top
  level LICENSE file for details.
*/

#ifndef TIDAS_SCHEMA_HPP
#define TIDAS_SCHEMA_HPP


namespace tidas {

	// one field of the schema

	class field {

		public :

			field ();

			bool operator== ( const field & other ) const;
			bool operator!= ( const field & other ) const;

			data_type type;
			std::string name;
			std::string units;

	};

	typedef std::vector < field > field_list;

	field_list field_filter_type ( field_list const & fields, data_type type );


	// base class for schema backend interface

	class schema_backend {

		public :
			
			schema_backend () {}
			virtual ~schema_backend () {}

			virtual schema_backend * clone () = 0;

			virtual void read_meta ( backend_path const & loc, std::string const & filter, field_list & fields ) = 0;

			virtual void write_meta ( backend_path const & loc, std::string const & filter, field_list const & fields ) = 0;

	};

	// memory backend class

	class schema_backend_mem : public schema_backend {

		public :
			
			schema_backend_mem ();
			~schema_backend_mem ();
			schema_backend_mem ( schema_backend_mem const & other );
			schema_backend_mem & operator= ( schema_backend_mem const & other );

			schema_backend * clone ();

			void read_meta ( backend_path const & loc, std::string const & filter, field_list & fields );

			void write_meta ( backend_path const & loc, std::string const & filter, field_list const & fields );

		private :

			field_list fields_;

	};

	// HDF5 backend class

	class schema_backend_hdf5 : public schema_backend {

		public :
			
			schema_backend_hdf5 ();
			~schema_backend_hdf5 ();
			schema_backend_hdf5 ( schema_backend_hdf5 const & other );
			schema_backend_hdf5 & operator= ( schema_backend_hdf5 const & other );

			schema_backend * clone ();

			void read_meta ( backend_path const & loc, std::string const & filter, field_list & fields );

			void write_meta ( backend_path const & loc, std::string const & filter, field_list const & fields );

	};


	// GetData backend class

	class schema_backend_getdata : public schema_backend {

		public :
			
			schema_backend_getdata ();
			~schema_backend_getdata ();
			schema_backend_getdata ( schema_backend_getdata const & other );
			schema_backend_getdata & operator= ( schema_backend_getdata const & other );

			schema_backend * clone ();

			void read_meta ( backend_path const & loc, std::string const & filter, field_list & fields );

			void write_meta ( backend_path const & loc, std::string const & filter, field_list const & fields );

	};


	// a schema used for a group

	class schema {

		public :

			schema ();
			~schema ();
			schema ( schema const & other );
			schema & operator= ( schema const & other );
			void copy ( schema const & other );

			schema ( backend_path const & loc, std::string const & filter );

			schema ( field_list const & fields );

			void read_meta ( std::string const & filter );

			void write_meta ( std::string const & filter );

			void relocate ( backend_path const & loc );

			backend_path location () const;

			schema duplicate ( std::string const & filter, backend_path const & newloc );

			//------------

			void clear ();
			
			void append ( field const & fld );
			
			void remove ( std::string const & name );
			
			field seek ( std::string const & name ) const;
			
			field_list fields () const;

		private :

			field_list fields_;

			backend_path loc_;
			std::unique_ptr < schema_backend > backend_;

	};

}


#endif
