var fs = require('fs'),
    path = require('path');

module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.initConfig({
    jshint: {
      all: ['Gruntfile.js', '**/*.js']
    }
  });

  grunt.registerTask('build', function(){
    // Do nothing. The gaia-essential should be a self-sustainable
    // module, and can become other's base.
  });
  grunt.registerTask('default', ['jshint']);
}
