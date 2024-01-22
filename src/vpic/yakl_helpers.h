#ifndef _yakl_helpers_h_
#define _yakl_helpers_h_

#include "YAKL.h"

#include "YAKL_Array.h"
#include "YAKL_memory_spaces.h"
#include "src/material/material.h"

#define FIELD_VAR_COUNT 16
#define FIELD_EDGE_COUNT 8
#define PARTICLE_VAR_COUNT 7
#define PARTICLE_MOVER_VAR_COUNT 3
#define ACCUMULATOR_VAR_COUNT 3
#define ACCUMULATOR_ARRAY_LENGTH 4
#define INTERPOLATOR_VAR_COUNT 18
#define MATERIAL_COEFFICIENT_VAR_COUNT 13
#define HYDRO_VAR_COUNT 14
#define NUM_J_DIMS 3

typedef int16_t material_id;

// TODO: yakl Array's size info should be initialized in constructors of each
// Array
//       which can only be defined in runtime.
// Memory location has been set to memDefault, which will be controled by
// library

// TODO: In yakl, memDevice will be set to memHost for CPU and SW runtime, and 
//       will be set to memDevice for CUDA, HIP and SYCL.
//       To migrate this program to YAKL, we should create some DS specify for 
//       host because there is not HostMirror in YAKL.
using y_counter_t = yakl::Array<int, 1, yakl::memDefault, yakl::styleDefault>;
// replacement of HostMirror in YAKL
using y_counter_t_h = yakl::Array<int, 1, yakl::memHost, yakl::styleDefault>;

using y_field_t = yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
// TODO: replacement of y_field_sa_t
using y_field_edge_t =
    yakl::Array<material_id, 2, yakl::memDefault, yakl::styleDefault>;
using y_field_accum_t =
    yakl::Array<float, 1, yakl::memDefault, yakl::styleDefault>;
using y_field_t_h = yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;
using y_field_edge_t_h = 
    yakl::Array<material_id, 2, yakl::memHost, yakl::styleDefault>;
using y_field_accum_t_h = 
    yakl::Array<float, 1, yakl::memHost, yakl::styleDefault>;

using y_jf_accum_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
using y_jf_accum_t_h = 
    yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;

using y_particles_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
using y_particles_i_t =
    yakl::Array<int, 1, yakl::memDefault, yakl::styleDefault>;
// replacement of HostMirror in YAKL
using y_particles_t_h =
    yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;
using y_particles_i_t_h = 
    yakl::Array<int, 1, yakl::memHost, yakl::styleDefault>;

using y_particle_copy_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
using y_particle_i_copy_t =
    yakl::Array<int, 1, yakl::memDefault, yakl::styleDefault>;
// replacement of HostMirror in YAKL
using y_particle_copy_t_h = 
    yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;
using y_particle_i_copy_t_h = 
    yakl::Array<int, 1, yakl::memHost, yakl::styleDefault>;

using y_particle_movers_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
using y_particle_i_movers_t =
    yakl::Array<int, 1, yakl::memDefault, yakl::styleDefault>;
// replacement of HostMirror in YAKL
using y_particle_movers_t_h = 
    yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;
using y_particle_i_movers_t_h = 
    yakl::Array<int, 1, yakl::memHost, yakl::styleDefault>;


using y_neighbor_t =
    yakl::Array<int64_t, 1, yakl::memDefault, yakl::styleDefault>;
using y_neighbor_t_h = 
    yakl::Array<int64_t, 1, yakl::memHost, yakl::styleDefault>;

using y_interpolator_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
using y_interpolator_t_h = 
    yakl::Array<float, 2, yakl::memHost, yakl::styleDefault>;

using y_accumulators_t =
    yakl::Array<float, 3, yakl::memDefault, yakl::styleDefault>;
// TODO: YAKL don't support scatterview, shoule we implement a replacement for
// it?

using y_hydro_d_t = yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;
// TODO replacement of y_hydro_sv_t

using y_material_coefficient_t =
    yakl::Array<float, 2, yakl::memDefault, yakl::styleDefault>;

// TODO: replacement of parallel_for_simd

namespace yakl_port {
namespace field_var {
enum f_v {
  ex = 0,
  ey = 1,
  ez = 2,
  div_e_err = 3,
  cbx = 4,
  cby = 5,
  cbz = 6,
  div_b_err = 7,
  tcax = 8,
  tcay = 9,
  tcaz = 10,
  rhob = 11,
  jfx = 12,
  jfy = 13,
  jfz = 14,
  rhof = 15
};
};
namespace field_edge_var {
enum f_e_v {
  ematx = 0,
  ematy = 1,
  ematz = 2,
  nmat = 3,
  fmatx = 4,
  fmaty = 5,
  fmatz = 6,
  cmat = 7
};
};

namespace interpolator_var {
enum i_r {
  ex = 0,
  dexdy = 1,
  dexdz = 2,
  d2exdydz = 3,
  ey = 4,
  deydz = 5,
  deydx = 6,
  d2eydzdx = 7,
  ez = 8,
  dezdx = 9,
  dezdy = 10,
  d2ezdxdy = 11,
  cbx = 12,
  dcbxdx = 13,
  cby = 14,
  dcbydy = 15,
  cbz = 16,
  dcbzdz = 17
};
};

namespace particle_var {
enum p_v {
  dx = 0,
  dy,
  dz,
  // pi = 3,
  ux,
  uy,
  uz,
  w,
};
};

namespace particle_mover_var {
enum p_m_v {
  dispx = 0,
  dispy = 1,
  dispz = 2,
  // pmi   = 3,
};
};

namespace accumulator_var {
enum a_v {
  jx = 0,
  jy = 1,
  jz = 2,
};
};

namespace material_coeff_var {
enum mc_v {
  decayx = 0,
  drivex = 1,
  decayy = 2,
  drivey = 3,
  decayz = 4,
  drivez = 5,
  rmux = 6,
  rmuy = 7,
  rmuz = 8,
  nonconductive = 9,
  epsx = 10,
  epsy = 11,
  epsz = 12,
};
};

namespace hydro_var {
enum h_v {
  jx = 0,
  jy = 1,
  jz = 2,
  rho = 3,
  px = 4,
  py = 5,
  pz = 6,
  ke = 7,
  txx = 8,
  tyy = 9,
  tzz = 10,
  tyz = 11,
  tzx = 12,
  txy = 13,
};
};
} // namespace yakl_port

void print_particles_d(
    y_particles_t particles,
    int np
);


#endif //_yakl_helpers_h_