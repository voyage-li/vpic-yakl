#include "yakl_helpers.h"



void print_particles_d(y_particles_t particles, int np) {
    using yakl::c::Bounds;
    using yakl::c::parallel_for;
    printf("Particle printer from 0 to %d \n", np);
    parallel_for("particle printer", yakl::c::Bounds<1>(0, 1), YAKL_LAMBDA (int i) {
        for (int z = 0; z < np; z ++) {
            printf("accum part %d has %f %f %f %f %f %f \n", z,
                    particles(z, particle_var::dx),
                    particles(z, particle_var::dy),
                    particles(z, particle_var::dz),
                    particles(z, particle_var::ux),
                    particles(z, particle_var::uy),
                    particles(z, particle_var::uz)
                  );
        }
    });
}